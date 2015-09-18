    marc_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_marc =                                                                                    

    " #define highp                                                                                                                              \n" 
      
      
    "    attribute      vec4   position;                                                                                                         \n" 
    "    attribute      vec2   textureCoords;                                                                                                    \n" 
         //====================================================                                                                                    
    "    uniform        mat4   HipsModelViewMatrix;                                                                                              \n"     
    "    uniform        mat4   HipsModelViewInverseMatrix;                                                                                       \n"
    "    uniform        mat4   HipsModelViewProjMatrix;                                                                                          \n"
         //----------------------------------------------------
    
    "    uniform        mat4   TorsoModelViewMatrix;                                                                                             \n"
    "    uniform        mat4   TorsoModelViewInverseMatrix;                                                                                      \n"
    "    uniform        mat4   TorsoModelViewProjMatrix;                                                                                         \n"
         
         //====================================================      
    "    uniform  highp float  selectMatrix;                                                                                                     \n"
    
         //====================================================      
    
    "    uniform  highp vec4   light_POSITION_01;                                                                                                \n"
    "    uniform        mat4   mvMatrix;                                                                                                         \n"
    "    uniform        mat4   mvpMatrix;                                                                                                        \n"
         //-----
    "    uniform        mat4   viewMatrix;                                                                                                       \n"
         //-----
    "    uniform        mat4   projectionShadow;                                                                                                 \n"
    "    uniform        mat4   modelViewShadow;                                                                                                  \n"
         //-----
    "    uniform        mat4   LightMatrix;                                                                                                      \n"
    //-------------------------------------------------                                                                
    "    varying highp  vec4   lightPosition_PASS;                                                                                               \n"
    "    varying highp  vec2   varTexcoord;                                                                                                      \n"
    //--------------------------------------------
    "    varying highp  vec4   shadowTexcoord;                                                                                                   \n"
    //--------------------------------------------
    "    const          mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);               \n"

    //==================================================================================================================================
    
    " void main()                                                                                                                                \n"
    " {                                                                                                                                          \n"
     
           
    "      if(selectMatrix == 1.0)                                                                                                                 \n"
    "      {                                                                                                                                     \n"
           
                 //-------------------------------------------------------------------------------    
    "            shadowTexcoord   =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * HipsModelViewMatrix * position;            \n"
    "            shadowTexcoord   =   shadowTexcoord / shadowTexcoord.w;                                                                         \n"
                 //-------------------------------------------------------------------------------
    "            varTexcoord             = textureCoords;                                                                                        \n"
    "            lightPosition_PASS      = normalize(HipsModelViewInverseMatrix * light_POSITION_01);                                            \n"
                 //-------------------------------------------------------------------------------
    "            gl_Position             = HipsModelViewProjMatrix * position;                                                                   \n"
    "      }                                                                                                                                     \n"
    //----------------------------------------------------------------------------------------------------------------------------------------
    "      else if(selectMatrix == 2.0)                                                                                                            \n"
    "      {                                                                                                                                     \n"

                 //-------------------------------------------------------------------------------
    "            shadowTexcoord   =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * TorsoModelViewMatrix * position;           \n"
    "            shadowTexcoord   =   shadowTexcoord / shadowTexcoord.w;                                                                         \n"
                 //-------------------------------------------------------------------------------
    "            varTexcoord             = textureCoords;                                                                                        \n"
    "            lightPosition_PASS      = normalize(TorsoModelViewInverseMatrix * light_POSITION_01);                                           \n"
                 //-------------------------------------------------------------------------------
    "            gl_Position             = TorsoModelViewProjMatrix * position;                                                                  \n"
    "      }                                                                                                                                     \n"

    " } \n";
    
    //===================================================================================================================================

    const GLchar *fragmentSource_marc =                                                                                  

    "#ifdef GL_ES                                                                                                                               \n"
    "#else                                                                                                                                      \n"
    "#define highp                                                                                                                              \n"
    "#endif                                                                                                                                     \n"
    //-----------------------------------------------------------------------------------------------------------------------------------
    "     uniform sampler2D    NormalMap;                                                                                                       \n"
    "             highp  vec3  NormalTex;                                                                                                       \n"
    "             highp float  NdotL1;                                                                                                          \n"
    //--------------------------------------------
    "    uniform sampler2D   ShadowTexture;                                                                                                     \n"
    "    varying highp vec4  shadowTexcoord;                                                                                                    \n"
    //--------------------------------------------
    "     uniform sampler2D    Texture1;                                                                                                        \n"
   
    "     uniform highp float  shininess;                                                                                                       \n"
    "     uniform highp float  ambient;                                                                                                         \n"
    //--------------------------------------------
    "     varying highp  vec4  lightPosition_PASS;                                                                                              \n"
    "     varying highp  vec2  varTexcoord;                                                                                                     \n"
    //--------------------------------------------
    "             highp  vec4  tempColor;                                                                                                       \n"
    "             highp  vec4  specular;                                                                                                        \n"
    //--------------------------------------------
    
    //=======================================================================================================================

   "void main()                                                                                                                                 \n"
    "{                                                                                                                                          \n"
                //---------------------------------------------------------------------------------------------------------------------
        "       highp float comp = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                                            \n"
        "       highp float depth_PowerVR = texture2DProj(ShadowTexture, shadowTexcoord).r;                                                     \n"
        "       highp float shadowVal = comp <= depth_PowerVR ? 1.0 : 0.4;                                                                      \n"
                //---------------------------------------------------------------------------------------------------------------------
        "       NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                                                   \n"
        "       NormalTex       =  normalize((NormalTex  - 0.5));                                                                               \n"
        "       NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);                                                                      \n"
                //----------------------------------------------------------------------------

                //----------------------------------------------------------------------------
        "       tempColor       =  pow(NdotL1, 50.0) * texture2D(Texture1, varTexcoord.xy) + texture2D(Texture1, varTexcoord.xy);               \n"

                //----------------------------------------------------------------------------
        "       gl_FragColor    =  tempColor * NdotL1 * NdotL1 * shadowVal *2.0;                                                                \n"
    "}\n";

    
      //--------------------------------------------------------------------------------------------------

        marc_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
        glShaderSource( marc_SHADER_VERTEX, 1, &vertexSource_marc, NULL );
        glCompileShader( marc_SHADER_VERTEX);                                              //glShaderBinary
        //----------------------------------------------------
        marc_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
        glShaderSource( marc_SHADER_FRAGMENT, 1, &fragmentSource_marc, NULL );
        glCompileShader(marc_SHADER_FRAGMENT);                                              //glShaderBinary                                 
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( marc_SHADER, marc_SHADER_VERTEX );                                                        
        glAttachShader( marc_SHADER, marc_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(marc_SHADER,   0, "position");                                                              
        glBindAttribLocation(marc_SHADER,   1, "normal");                                                            
        glBindAttribLocation(marc_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( marc_SHADER_VERTEX);                                                                             
        glDeleteShader( marc_SHADER_FRAGMENT);                                                                           
        glLinkProgram(marc_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_marc               = glGetUniformLocation(marc_SHADER, "mvMatrix");                  
        UNIFORM_MODELVIEWPROJ_marc           = glGetUniformLocation(marc_SHADER, "mvpMatrix");  
        //-------------------------------      
        UNIFORM_viewMatrix_marc              = glGetUniformLocation(marc_SHADER, "viewMatrix");              
        //-------------------------------
        UNIFORM_SHADOW_PROJ_marc             = glGetUniformLocation(marc_SHADER, "projectionShadow");                                                  
        UNIFORM_modelViewShadow_marc         = glGetUniformLocation(marc_SHADER, "modelViewShadow");            
        //-------------------------------      
        UNIFORM_LIGHT_MATRIX_marc            = glGetUniformLocation(marc_SHADER, "LightMatrix");                
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_marc       = glGetUniformLocation(marc_SHADER, "light_POSITION_01");          
        UNIFORM_shininess_marc               = glGetUniformLocation(marc_SHADER, "shininess");  
       
        UNIFORM_ambient_marc                 = glGetUniformLocation(marc_SHADER, "ambient");  
          
        UNIFORM_ShadowTexture_marc           = glGetUniformLocation(marc_SHADER, "ShadowTexture");           
        UNIFORM_TEXTURE_DOT3_marc            = glGetUniformLocation(marc_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_marc                 = glGetUniformLocation(marc_SHADER, "Texture1"); 
        //================================================================================================================
        UNIFORM_MODELVIEW_HIPS_marc                  = glGetUniformLocation(marc_SHADER, "HipsModelViewMatrix");                
        UNIFORM_MODELVIEW_INVERSE_HIPS_marc          = glGetUniformLocation(marc_SHADER, "HipsModelViewInverseMatrix");          
        UNIFORM_MODELVIEW_PROJ_HIPS_marc             = glGetUniformLocation(marc_SHADER, "HipsModelViewProjMatrix");          
        //--------------------------------------
        UNIFORM_MODELVIEW_TORSO_marc                 = glGetUniformLocation(marc_SHADER, "TorsoModelViewMatrix");        
        UNIFORM_MODELVIEW_INVERSE_TORSO_marc         = glGetUniformLocation(marc_SHADER, "TorsoModelViewInverseMatrix");        
        UNIFORM_MODELVIEW_PROJ_TORSO_marc            = glGetUniformLocation(marc_SHADER, "TorsoModelViewProjMatrix");        
        //================================================================================================================        
        
        UNIFORM_MATRIX_BLOCK_SELECTION                 = glGetUniformLocation(marc_SHADER, "selectMatrix");  
 

         

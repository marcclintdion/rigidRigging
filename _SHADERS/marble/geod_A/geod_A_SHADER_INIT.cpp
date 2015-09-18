    geod_A_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_geod_A =                                                                                    

      " #define highp                                                                                                                         \n" 
      
      
                                                                                      
      "    //-------------------------------------------------                                                                                \n"     
      "    uniform  highp vec4  light_POSITION_01;                                                                                            \n" 
      "    uniform        mat4  mvMatrix;                                                                                                     \n" 
      "    uniform        mat4  mvpMatrix;                                                                                                    \n" 
           //-----
      "    uniform        mat4  viewMatrix;                                                                                                   \n"                   
           //-----
      "    uniform        mat4  projectionShadow;                                                                                             \n"        
      "    uniform        mat4  modelViewShadow;                                                                                              \n"        
           //-----
      "    uniform        mat4  lightMatrix;                                                                                                  \n" 
           //-----
      "    attribute      vec4   position;                                                                                                        \n"      
      "                   vec4   TEMP_position;                                                                                                        \n"      
           //-----                                                                                                                                     \n" 
      "    uniform        mat4  TextureMatrix;                                                                                                    \n" 
     
      "    attribute      vec2 textureCoords;                                                                                                     \n"
   
    //-------------------------------------------------                                                                
    "      varying highp  vec4  lightPosition_PASS;                                                                                           \n" 
    "      varying highp  vec2  varTexcoord;                                                                                                  \n" 
    //--------------------------------------------
    "      varying highp  vec4  shadowTexcoord;                                                                                               \n"       
    //--------------------------------------------
    "      const          mat4  ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);           \n"  

    //==================================================================================================================================
    
    " void main()                                                                                                                             \n" 
    " {                                                                                                                                       \n" 
    "            TEMP_position           =  mvpMatrix * position;                                                                                 \n"           
     
                 //-------------------------------------------------------------------------------    
    "            shadowTexcoord   =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;                                                         \n" 
    "            shadowTexcoord   =   shadowTexcoord / shadowTexcoord.w;                                                                      \n"      
                 //-------------------------------------------------------------------------------

    "            varTexcoord             = textureCoords;                                                                                     \n" 
    "            lightPosition_PASS      = normalize(lightMatrix * (light_POSITION_01 + TEMP_position));                                                        \n" 
                                           
    "            gl_Position             = TEMP_position;                                                                              \n" 
    
    " } \n";   
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_geod_A =                                                                                  

    "#ifdef GL_ES                                                                                                                           \n" 
    "#else                                                                                                                                  \n" 
    "#define highp                                                                                                                          \n" 
    "#endif                                                                                                                                 \n" 
    //-----------------------------------------------------------------------------------------------------------------------------------
    "     uniform sampler2D    NormalMap;                                                                                                   \n" 
    "             highp  vec3  NormalTex;                                                                                                   \n" 
    "             highp float  NdotL1;                                                                                                      \n" 
    //--------------------------------------------
    "    uniform sampler2D   ShadowTexture;                                                                                                 \n"   
    "    varying highp vec4  shadowTexcoord;                                                                                                \n"       
    //--------------------------------------------
    "     uniform sampler2D    Texture1;                                                                                                    \n"     
   
    "     uniform highp float  shininess;                                                                                                   \n"    
    "     uniform highp float  ambient;                                                                                                     \n" 
    //--------------------------------------------                                                                      
    "     varying highp  vec4  lightPosition_PASS;                                                                                          \n" 
    "     varying highp  vec2  varTexcoord;                                                                                                 \n" 
    //--------------------------------------------                                                                       
    "             highp  vec4  tempColor;                                                                                                   \n" 
    "             highp  vec4  specular;                                                                                                    \n"     
    //-------------------------------------------- 
                                                                
    //=======================================================================================================================                      
   
   "void main()                                                                                                                             \n" 
    "{                                                                                                                                      \n" 
        
        //---------------------------------------------------------------------------------------------------------------------
        "       highp float comp = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                                       \n" 
        "       highp float depth_PowerVR = texture2DProj(ShadowTexture, shadowTexcoord).r;                                                \n" 
        "       highp float shadowVal = comp <= depth_PowerVR ? 1.0 : 0.4;                                                                 \n" 
                //---------------------------------------------------------------------------------------------------------------------
        "       NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                                              \n" 
        "       NormalTex       =  normalize((NormalTex  - 0.5));                                                                          \n" 
        "       NdotL1          =  max(dot(NormalTex, lightPosition_PASS.xyz), 0.0);                                                                 \n"   
                //----------------------------------------------------------------------------         

                //----------------------------------------------------------------------------                           
        "       tempColor       =  max(pow(NdotL1, 50.0), 0.0) * texture2D(Texture1, varTexcoord.xy) + texture2D(Texture1, varTexcoord.xy);               \n" 
        "       gl_FragColor    =   tempColor * NdotL1 * NdotL1 * shadowVal;                                                                      \n" 
    

    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        geod_A_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( geod_A_SHADER_VERTEX, 1, &vertexSource_geod_A, NULL );                                        
        glCompileShader( geod_A_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        geod_A_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( geod_A_SHADER_FRAGMENT, 1, &fragmentSource_geod_A, NULL );                                    
        glCompileShader(geod_A_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( geod_A_SHADER, geod_A_SHADER_VERTEX );                                                        
        glAttachShader( geod_A_SHADER, geod_A_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(geod_A_SHADER,   0, "position");                                                              
        glBindAttribLocation(geod_A_SHADER,   1, "normal");                                                            
        glBindAttribLocation(geod_A_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( geod_A_SHADER_VERTEX);                                                                             
        glDeleteShader( geod_A_SHADER_FRAGMENT);                                                                           
        glLinkProgram(geod_A_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_geod_A               = glGetUniformLocation(geod_A_SHADER, "mvMatrix");                  
        UNIFORM_MODELVIEWPROJ_geod_A           = glGetUniformLocation(geod_A_SHADER, "mvpMatrix");  
        //-------------------------------      
        UNIFORM_viewMatrix_geod_A              = glGetUniformLocation(geod_A_SHADER, "viewMatrix");              
        //-------------------------------
        UNIFORM_SHADOW_PROJ_geod_A             = glGetUniformLocation(geod_A_SHADER, "projectionShadow");                                                  
        UNIFORM_modelViewShadow_geod_A         = glGetUniformLocation(geod_A_SHADER, "modelViewShadow");            
        //-------------------------------      
        UNIFORM_LIGHT_MATRIX_geod_A            = glGetUniformLocation(geod_A_SHADER, "lightMatrix");                
        UNIFORM_TEXTURE_MATRIX_geod_A          = glGetUniformLocation(geod_A_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_geod_A       = glGetUniformLocation(geod_A_SHADER, "light_POSITION_01");          
        UNIFORM_shininess_geod_A               = glGetUniformLocation(geod_A_SHADER, "shininess");  
       
        UNIFORM_ambient_geod_A                 = glGetUniformLocation(geod_A_SHADER, "ambient");  
          
        UNIFORM_ShadowTexture_geod_A           = glGetUniformLocation(geod_A_SHADER, "ShadowTexture");           
        UNIFORM_TEXTURE_DOT3_geod_A            = glGetUniformLocation(geod_A_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_geod_A                 = glGetUniformLocation(geod_A_SHADER, "Texture1");  

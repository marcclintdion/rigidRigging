
GLuint        boxCount                                         =  1;
GLuint        selectedModel                                    =  0;     

GLfloat       collisionBoxArray[500][32];                                    
                         
//---------------------------------------------------------------------------------------
var           scaleScreenAlignedQuadRatio                      = 0.0;

var           inverseScreenRatio;     

//---------------------------------------------------------------------------------------                         

                       
//----------------------------------------------------------------------           
             
             
             

GLuint          fbo,
                color,
                depth,
                mainLightPass_fboId,
                mainLightPass_depth,
                textureID,
                fboId_3D,
                fboId,
                componentShaderPass_fbo,
                componentShaderPass_color,
                componentShaderPass_depth,
                flatten_3D_SHADOW_fboId,
                flatten_3D_SHADOW_TEXTURE,
                framebuffer,
                colorRenderbuffer,
                depthRenderbuffer;

//---------------------------------------------------------------------------------------

var           fieldOfView                                      =     30.0;

//---------------------------------------------------------------------------------------
GLsizei       resize_SHADOW_FBO = 1;
GLsizei       resize_LIGHTS_FBO = 4;

var           adjustNearFar[]                                  =  {  0.1, 250.0 };

//---------------------------------------------------------------------------------------
var           moveSet[]       =  {0.0, 0.0, -4.5, 1.0};

var           lookAt[]                                         =  {0, 0, -11.85, 1.0};
//---------------------------------------------------------------------------------------
var           eyepositionCamera[]                              =  {  0, 0.0, 0.0, 0.0};

var           camera_POSITION[]                                =  {  0, 0.0, 0.0, 0.0};
//---------------------------------------------------------------------------------------
#ifdef WIN32   
var           eyeposition[]                                    =  {0, 0.0, 0.0, 0.0};

#endif 
#ifdef __APPLE__   
var           eyeposition[]                                    =  {0, 0.0, 0.0, 0.0};
#endif 


var           eyeStartPosition[]                               =  {-0, 0.0, 0.0, 0.0};


var           rotateModelWithMiddleMouse[]                       =  {0.0, 0.0};
var           zoomModelWithMiddleMouse                           =  0.0;
var           moveModelWithMiddleMouse[]                         =  {0.0, 0.0};
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------

var           turnTable                                        =     0.0;
var           scaleTurnTable                                   =     1.0;  //=0.01178;
//---------------------------------------------------------------------------------------
var           upVector[]             	                       =  {  0.0, 1.0, 0.0};
//---------------------------------------------------------------------------------------
var           moveShadow[]                                     =  {  0.0, 0.0, 0.0};
var           matchColorModelToShadowPosition[]                =  {  0.0, 0.0, 0.0, 0.0};

var           eyeposition_SHADOW[]                             =  {-2.65002, -0.38, -4.97009, 1.0};//__LONGER_SHADOWS


var           lookAt_SHADOW[]                                  =  {  0.0, 0.0, 0.0};
var           adjustLookAtMove[]                               =  {  0.0, 0.0, 0.0};

var           shadowsPositionOffset[]	                       =  {  0.5, 0.5, 0.5 };//BIAS_MATRIX
var           scaleShadows                                     =     0.5;//__________//BIAS_MATRIX

var           offset[]                                         =  {  0.0, 0.0, 0.0, 0.0};
var           offset_ShadowShader[]                            =  {  0.0, 0.0, 0.0, 0.0};

var           scaleShadowSize                                  =     1.0;

var           offsetFinalShadow[]                              =  {  0, 0, 0, 0.0}; //_ADJUSTMENT_IN_THE_FINAL_COLOR_SHADER

var           scaleMoveShadows[]	                           =  {  1.0, 1.0, 1.0, 0.0};//=  {0.971, 0.937001, 1.043, 0.0};


//============================================================================================================================



//===========================================================================================
//GLfloat      frameBufferPlane_SCALE[]                                                    =  { 1.84778, 1.0,  1.0, 1.0};
//#include    "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Globals.cpp"
//===============================================================================================================================
GLuint       UNIFORM_screenRatio_frameBufferPlane_GaussianVertical;
GLfloat      screenRatio;
//------------------------------------------
//GLuint       gaussianBlurHorizontal_TEXTURE, gaussianBlurVertical_TEXTURE, mainLightPass_TEXTURE, geometryLightPass_TEXTURE;
//GLfloat      frameBufferPlane_GaussianHorizontal_blurRadius                              =   0.00530001;
//GLfloat      frameBufferPlane_GaussianVertical_blurRadius                                =   0.00530001;
//#include    "_MODEL_FOLDERS_/frameBufferPlane/gaussianBlur_GLOBALS.cpp"
//==============================================================================================================================
//-------------------------                         
//==============================================================================================================================
                          
                         
                         
            
                         
                         
//==============================================================================================================================
//-------------------------                         
//==============================================================================================================================                          
                               //#######################################___SHADERS___##################################################
                               GLuint        fboId_2D;
                               GLuint        shadowMap_TEXTURE;
                               #include    "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_GLOBALS.cpp"
                               //===========================================================================================
                               //#include    "_SHADERS/SHADOWS/flatten_3D_shadow_SHADER_GLOBALS.cpp"                              
                               //====================================================================================
                              


                               //#######################################___MODELS___##################################################


                               #include "_MODEL_FOLDERS_/floorTile_2m/floorTile_2m_Globals.cpp"                                                                
                               //====================================================================================                                                            
                               //====================================================================================                                

        //============================================================
        #include "_MODEL_FOLDERS_/marc/SHADER/marc_SHADER_GLOBALS.cpp"
        //=========---------------------------------------------------
        #include "_MODEL_FOLDERS_/marc/marc_GLOBALS.cpp"        
        //------------------------------------------------ 
        #include "_MODEL_FOLDERS_/hips/hips_GLOBALS.cpp"
        //------------------------------------------------
        #include "_MODEL_FOLDERS_/torso/torso_GLOBALS.cpp"

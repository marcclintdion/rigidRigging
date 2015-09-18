                 
var         leaves_A_LIGHT_POSITION_01[]     =  {  0.0, 10.0, 50.0, 1};

var         ambient_leaves_A         =      1.0; 
var         shininess_leaves_A         =  7.44999;

                                      
//=====================================================================================|_SHADER
GLuint      leaves_A_SHADER_VERTEX;                                                                                 
GLuint      leaves_A_SHADER_FRAGMENT;                                                                               
GLuint      leaves_A_SHADER;     
//-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
GLuint      UNIFORM_LIGHT_POSITION_01_leaves_A;                                                                     
GLuint      UNIFORM_LIGHT_POSITION_02_leaves_A; 
GLuint      UNIFORM_LIGHT_POSITION_03_leaves_A; 
GLuint      UNIFORM_shininess_leaves_A;
GLuint      UNIFORM_ambient_leaves_A;
GLuint      UNIFORM_counter_leaves_A;                                                                               
//-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                                                             
GLuint      UNIFORM_tileJump_leaves_A;                                                                              
//-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
GLuint      UNIFORM_MODELVIEW_leaves_A;                                                                             
GLuint      UNIFORM_MODELVIEWPROJ_leaves_A;                                                                         
//----
GLuint      UNIFORM_SHADOW_PROJ_leaves_A;
GLuint      UNIFORM_modelViewShadow_leaves_A;
//----
GLuint      UNIFORM_viewMatrix_leaves_A; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_leaves_A;                                                                          
GLuint      UNIFORM_TEXTURE_MATRIX_leaves_A;                                                                        
//-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
GLuint      UNIFORM_ShadowTexture_leaves_A;                                                                        
GLuint      UNIFORM_TEXTURE_DOT3_leaves_A;                                                                          
GLuint      UNIFORM_TEXTURE_leaves_A; 

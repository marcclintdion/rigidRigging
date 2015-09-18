                    
var         geod_A_LIGHT_POSITION_01[]     =  {500, 500.0, 1000.0, 1};

var         ambient_geod_A         =      0.0539995; 
var         shininess_geod_A         =  38.95;


//--------------------------------------------------
                                    
//=====================================================================================|_SHADER
GLuint      geod_A_SHADER_VERTEX;                                                                                 
GLuint      geod_A_SHADER_FRAGMENT;                                                                               
GLuint      geod_A_SHADER;     
//-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
GLuint      UNIFORM_LIGHT_POSITION_01_geod_A;                                                                     
GLuint      UNIFORM_LIGHT_POSITION_02_geod_A; 
GLuint      UNIFORM_LIGHT_POSITION_03_geod_A; 
GLuint      UNIFORM_shininess_geod_A;
GLuint      UNIFORM_ambient_geod_A;
GLuint      UNIFORM_counter_geod_A;                                                                               
//-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                                                              
GLuint      UNIFORM_tileJump_geod_A;                                                                              
//-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
GLuint      UNIFORM_MODELVIEW_geod_A;                                                                             
GLuint      UNIFORM_MODELVIEWPROJ_geod_A;                                                                         
//----
GLuint      UNIFORM_SHADOW_PROJ_geod_A;
GLuint      UNIFORM_modelViewShadow_geod_A;
//----
GLuint      UNIFORM_viewMatrix_geod_A; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_geod_A;                                                                          
GLuint      UNIFORM_TEXTURE_MATRIX_geod_A;                                                                        
//-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
GLuint      UNIFORM_ShadowTexture_geod_A;                                                                        
GLuint      UNIFORM_TEXTURE_DOT3_geod_A;                                                                          
GLuint      UNIFORM_TEXTURE_geod_A; 

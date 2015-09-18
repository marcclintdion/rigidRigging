var         marc_LIGHT_POSITION_01[]     =  {  0.0, 10.0, 50.0, 1};

var         ambient_marc         =      1.0; 
var         shininess_marc         =  7.44999;
//=====================================================================================
GLuint      marc_SHADER_VERTEX;                                                                                 
GLuint      marc_SHADER_FRAGMENT;                                                                               
GLuint      marc_SHADER;     
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_LIGHT_POSITION_01_marc;                                                                     
GLuint      UNIFORM_LIGHT_POSITION_02_marc; 
GLuint      UNIFORM_LIGHT_POSITION_03_marc; 
GLuint      UNIFORM_shininess_marc;
GLuint      UNIFORM_ambient_marc;
GLuint      UNIFORM_counter_marc;                                                                               
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_MODELVIEW_marc;                                                                             
GLuint      UNIFORM_MODELVIEWPROJ_marc;                                                                         
//----
GLuint      UNIFORM_SHADOW_PROJ_marc;
GLuint      UNIFORM_modelViewShadow_marc;
//----
GLuint      UNIFORM_viewMatrix_marc; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_marc;                                                                          
GLuint      UNIFORM_TEXTURE_MATRIX_marc;                                                                        
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_ShadowTexture_marc;                                                                        
GLuint      UNIFORM_TEXTURE_DOT3_marc;                                                                          
GLuint      UNIFORM_TEXTURE_marc; 
//==============================================================================
//==============================================================================
GLuint      UNIFORM_MODELVIEW_HIPS_marc;
GLuint      UNIFORM_MODELVIEW_INVERSE_HIPS_marc;
GLuint      UNIFORM_MODELVIEW_PROJ_HIPS_marc;
//----
var         HipsModelViewMatrix[16];
var         HipsModelViewInverseMatrix[16];
var         HipsModelViewProjMatrix[16];
//==============================================
GLuint      UNIFORM_MODELVIEW_TORSO_marc;
GLuint      UNIFORM_MODELVIEW_INVERSE_TORSO_marc;
GLuint      UNIFORM_MODELVIEW_PROJ_TORSO_marc;
//----
var         TorsoModelViewMatrix[16];
var         TorsoModelViewInverseMatrix[16];
var         TorsoModelViewProjMatrix[16];
//==============================================

//==============================================
GLuint      UNIFORM_MATRIX_BLOCK_SELECTION;
var         marcMatrixBlockSelection;









 
 
 glUseProgram(marc_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------
          glUniform4f(UNIFORM_LIGHT_POSITION_01_marc,              marc_LIGHT_POSITION_01[0],
                                                                   marc_LIGHT_POSITION_01[1],
                                                                   marc_LIGHT_POSITION_01[2],
                                                                   marc_LIGHT_POSITION_01[3]);
         
          glUniform1f(UNIFORM_shininess_marc,                      shininess_marc);
          glUniform1f(UNIFORM_ambient_marc,                        ambient_marc);

          //=================================================================================================
          glUniformMatrix4fv(UNIFORM_MODELVIEW_HIPS_marc,            1, 0,    HipsModelViewMatrix);          
          glUniformMatrix4fv(UNIFORM_MODELVIEW_INVERSE_HIPS_marc,    1, 0,    HipsModelViewInverseMatrix);            
          glUniformMatrix4fv(UNIFORM_MODELVIEW_PROJ_HIPS_marc,       1, 0,    HipsModelViewProjMatrix);            
          
          //-----------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_TORSO_marc,           1, 0,    TorsoModelViewMatrix);           
          glUniformMatrix4fv(UNIFORM_MODELVIEW_INVERSE_TORSO_marc,   1, 0,    TorsoModelViewInverseMatrix);           
          glUniformMatrix4fv(UNIFORM_MODELVIEW_PROJ_TORSO_marc,      1, 0,    TorsoModelViewProjMatrix);           
          
          //=================================================================================================        
          glUniform1f(UNIFORM_MATRIX_BLOCK_SELECTION,  marcMatrixBlockSelection);          
      
          //=================================================================================================            
          
          glUniformMatrix4fv(UNIFORM_MODELVIEW_marc,       1, 0,         modelView);
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_marc,   1, 0,         mvpMatrix);
          //---------------     
          glUniformMatrix4fv(UNIFORM_viewMatrix_marc,      1, 0,         viewMatrix);
          //---------------     
          glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_marc,     1, 0,         ProjectionShadow);
          glUniformMatrix4fv(UNIFORM_modelViewShadow_marc, 1, 0,         modelViewShadow);
          //---------------
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_marc,    1, 0,         lightMatrix);
         //-------------------------------------------------------------------------------------------------
          glUniform1i(UNIFORM_ShadowTexture_marc,  3);
          glUniform1i(UNIFORM_TEXTURE_DOT3_marc,   1);
          glUniform1i(UNIFORM_TEXTURE_marc,        0);
    //====================================================================================================================

//---------------------------------------------------------------
glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
//---  

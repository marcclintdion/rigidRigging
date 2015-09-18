
   MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    //Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   
 
 
 
 glUseProgram(geod_A_SHADER);          
          //------------------------------------------------------------------------------         
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);	                                                                                          
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                 
          glEnableVertexAttribArray(2);                                                                                               
          //------------------------------------------------------------------------------------------------                                
          glUniform4f(UNIFORM_LIGHT_POSITION_01_geod_A,          geod_A_LIGHT_POSITION_01[0]*marble_scaleLights+eyeposition[0],                       
                                                                       geod_A_LIGHT_POSITION_01[1]*marble_scaleLights+eyeposition[0],                       
                                                                       geod_A_LIGHT_POSITION_01[2]*marble_scaleLights+eyeposition[0],                       
                                                                       geod_A_LIGHT_POSITION_01[3]*marble_scaleLights+eyeposition[0]);                      
                           
         
          glUniform1f(UNIFORM_shininess_geod_A,                  shininess_geod_A);
          glUniform1f(UNIFORM_ambient_geod_A,                    ambient_geod_A);   
        
          //------------------------------------------------------------------------------------------------
          glUniformMatrix4fv(UNIFORM_MODELVIEW_geod_A,       1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_geod_A,   1, 0,         mvpMatrix);                                   
          //---------------     
          glUniformMatrix4fv(UNIFORM_viewMatrix_geod_A,      1, 0,         viewMatrix);     
          //---------------     
          glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_geod_A,     1, 0,         ProjectionShadow);
          glUniformMatrix4fv(UNIFORM_modelViewShadow_geod_A, 1, 0,         modelViewShadow);    
          //---------------                                                                                                                                      //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_geod_A, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_geod_A,    1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_geod_A,  1, 0,         textureMatrix);                                       
          //-------------------------------------------------------------------------------------------------                                
          glUniform1i(UNIFORM_ShadowTexture_geod_A,  3);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_geod_A,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_geod_A,        0);                                                        
    //====================================================================================================================

//---------------------------------------------------------------
glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
//---  



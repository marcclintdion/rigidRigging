            shaderNumber = 50;//plastic/rubber/                                                                               
            setupTransforms_MainColor();                                                                                      
    glBindBuffer(GL_ARRAY_BUFFER, marc_VBO);                                                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, marc_INDICES_VBO);                                                                                                                                
    //----------------------------------------------------------------------------------------------------------------------------------------------           
    Translate(modelView, marc_POSITION[0], marc_POSITION[1], marc_POSITION[2]);                          
    Rotate(modelView, marc_ROTATE[0], marc_ROTATE[1], marc_ROTATE[2], marc_ROTATE[3]); 

//======================================================================================================                                                       
    SelectShader(shaderNumber);                                                                                                                              
//======================================================================================================                                                       

    glActiveTexture ( GL_TEXTURE1 );                                                                                                                           
    glBindTexture(GL_TEXTURE_2D, marc_NORMALMAP);                                                                                            
    //---                                                                                                                                                      
    glActiveTexture (GL_TEXTURE0);                                                                                                                             
    glBindTexture(GL_TEXTURE_2D, marc_TEXTUREMAP);                                                                                           
    //---------------------------------------------------------------------------------------------------------------------------------------------------      
    glDrawElements(GL_TRIANGLES, 8214, GL_UNSIGNED_INT, 0);                                                                                                     


            shaderNumber = 100;//plastic/rubber/                                                                               
            setupTransforms_MainColor();                                                                                      
        glBindBuffer(GL_ARRAY_BUFFER, torso_VBO);                                                                                                 
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torso_INDICES_VBO);                                                                                                                                
    //===========================================================================================
    AssignMatrix(TorsoModelViewMatrix, modelView);
    //--------------------------------------------
    Translate(TorsoModelViewMatrix, torso_POSITION[0], torso_POSITION[1], torso_POSITION[2]);
    Rotate(TorsoModelViewMatrix, torso_ROTATE[0], torso_ROTATE[1], torso_ROTATE[2], torso_ROTATE[3]);
    //-------------------------------------------------------------------------------------------
    LoadIdentity(TorsoModelViewInverseMatrix);
    InvertMatrix(TorsoModelViewInverseMatrix, TorsoModelViewMatrix);
    //-------------------------------------------------------------------------------------------
    MultiplyMatrix(TorsoModelViewProjMatrix, projection, TorsoModelViewMatrix);
    //-------------------------------------------------------------------------------------------
    marcMatrixBlockSelection     = 2;


//======================================================================================================                                                       
    SelectShader(shaderNumber);                                                                                                                              
//======================================================================================================                                                       
    //---------------------------------------------------------------------------------------------------------------------------------------------------      
    glDrawElements(GL_TRIANGLES, 1428, GL_UNSIGNED_INT, 0);                                                                                                     


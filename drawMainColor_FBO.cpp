
//glBindFramebuffer(GL_FRAMEBUFFER, mainLightPass_fboId);
//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mainLightPass_depth);
 

        //=======================================================================================================================
        glClearColor( 0.7, 0.7, 0.7, 1.0 );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        //----------------------------------------------------------------------------------
        
           //=======================================================================================================================
        #ifdef WIN32
                
                //-------------------------------------------------------------------------------------------------------               
                glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
                PerspectiveMatrix(projection, fieldOfView, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar[0],  adjustNearFar[1]);
                //-------------------------------------------------------------------------------------------------------          
                                                      //+((GLfloat)viewWidth / (GLfloat)viewHeight)
        
        #endif
        //=======================================================================================================================
     
        //=======================================================================================================================
        #ifdef __APPLE__
                               //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
                //-------------------------------------------------------------------------------------------------------               
                glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
                PerspectiveMatrix(projection, fieldOfView+14, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar[0],  adjustNearFar[1]);
                //-------------------------------------------------------------------------------------------------------  
                Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
                //-------------------------------------------------------------------------------------------------------          
        #endif                 //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
        //=======================================================================================================
 
 


        //====================================================================================        
        #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_SHUTDOWN.cpp"
        //====================================================================================
        #include "_MODEL_FOLDERS_/marc/SHADER/marc_SHADER_SHUTDOWN.cpp"
        //====================================================================================        
                    if(m_uiShadowMapTexture != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &m_uiShadowMapTexture);                                                                  
                            m_uiShadowMapTexture = 0;                                                                                    
                    }           
                    if(m_uiFrameBufferObject != 0)                                                                                        
                    {                                                                                                              
                            glDeleteFramebuffers(1, &m_uiFrameBufferObject);                                                                  
                            m_uiFrameBufferObject = 0;                                                                                    
                    }           
        
        //#include "_MODEL_FOLDERS_/floorTile_2m/floorTile_2m_Shutdown.cpp"                                                               

        //=================================================================================
        #include "_MODEL_FOLDERS_/hips/hips_SHUTDOWN.cpp"

        //=================================================================================
        #include "_MODEL_FOLDERS_/torso/torso_SHUTDOWN.cpp"

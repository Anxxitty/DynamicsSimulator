include_directories(src)

add_executable (DynamicsSimulator "src/Main.cpp" 
                                  "src/DynamicsSimulator.h" 
                                      "src/Display/Graphics.cpp" 
                                      "src/Display/Graphics.h"
                                      
                                      "src/Physics/Physics.h" 
                                          "src/Physics/Force/Force.cpp" 
                                          "src/Physics/Force/Force.h"
                                          
                                          "src/Physics/Objects/Hitbox.cpp"
                                          "src/Physics/Objects/Hitbox.h"
                                          "src/Physics/Objects/MovableObject.cpp"
                                          "src/Physics/Objects/MovableObject.h"

                                          "src/Physics/ReferenceFrames/NoFrictionTerrestrialReferenceFrame.cpp"
                                          "src/Physics/ReferenceFrames/NoFrictionTerrestrialReferenceFrame.h"
                                          "src/Physics/ReferenceFrames/ReferenceFrame.cpp"
                                          "src/Physics/ReferenceFrames/ReferenceFrame.h"

                                          "src/Physics/Vector/Vector2D.cpp"
                                          "src/Physics/Vector/Vector2D.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DynamicsSimulator PROPERTY CXX_STANDARD 20)
endif()

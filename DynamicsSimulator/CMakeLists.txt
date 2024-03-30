include_directories(src)

add_executable (DynamicsSimulator "src/Main.cpp"
                                  "src/Scene.h"
                                  "src/Scene.cpp"
                                  "src/DynamicsSimulator.h"                                      
                                      
                                      "src/Display/Graphics.h"
                                      "src/Display/Widget.h"
                                      "src/Display/Widget.cpp"
                                      
                                      "src/Physics/Physics.h" 
                                          "src/Physics/Force/Force.h" 
                                          "src/Physics/Force/Force.cpp"
                                         
                                          "src/Physics/Objects/Hitbox.h"
                                          "src/Physics/Objects/Hitbox.cpp"
                                          "src/Physics/Objects/MovableObject.h"
                                          "src/Physics/Objects/MovableObject.cpp"

                                          "src/Physics/ReferenceFrames/NoFrictionTerrestrialReferenceFrame.h"
                                          "src/Physics/ReferenceFrames/NoFrictionTerrestrialReferenceFrame.cpp"
                                          "src/Physics/ReferenceFrames/ReferenceFrame.h"
                                          "src/Physics/ReferenceFrames/ReferenceFrame.cpp"

                                          "src/Physics/Vector/Vector2D.h"
                                          "src/Physics/Vector/Vector2D.cpp"
)
target_link_libraries(DynamicsSimulator PRIVATE sfml-graphics)
target_compile_features(DynamicsSimulator PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET DynamicsSimulator
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:DynamicsSimulator>
        VERBATIM)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DynamicsSimulator PROPERTY CXX_STANDARD 20)
endif()

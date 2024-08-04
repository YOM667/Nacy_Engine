set(PROJECT_NAME NacyEngine)

################################################################################
# Source groups
################################################################################
set(SOURCE
    "Sources/Nacy/Core/Application.h"
    "Sources/Nacy/Core/Core.h"
    "Sources/Nacy/Core/Event/Event.h"
    "Sources/Nacy/Core/Event/Events/KeyEvent.hpp"
    "Sources/Nacy/Core/Event/Events/MouseEvent.hpp"
    "Sources/Nacy/Core/Event/Events/WindowEvent.hpp"
    "Sources/Nacy/Core/GameWindow.h"
    "Sources/Nacy/Manager/Assets/ResourceManager.h"
    "Sources/Nacy/Manager/Camera/Camera.h"
    "Sources/Nacy/Manager/Input/InputManager.h"
    "Sources/Nacy/Manager/OpenGL/GLManager.h"
    "Sources/Nacy/Manager/Scene/Scene.h"
    "Sources/Nacy/Manager/Scene/SceneManager.h"
    "Sources/Nacy/Manager/Shader/Shader.h"
    "Sources/Nacy/Math/Vector.h"
    "Sources/Nacy/Object/Components/Component.hpp"
    "Sources/Nacy/Object/Components/Game/DelayComponent.hpp"
    "Sources/Nacy/Object/Components/Game/SpriteComponent.hpp"
    "Sources/Nacy/Object/Components/Game/TransformComponent.hpp"
    "Sources/Nacy/Object/Components/Interface/ShapeComponent.hpp"
    "Sources/Nacy/Object/Components/Interface/TextLabelComponent.hpp"
    "Sources/Nacy/Object/GameObject.h"
    "Sources/Nacy/Render/Graphic.hpp"
    "Sources/Nacy/Render/Renderer.h"
    "Sources/Nacy/Render/Shape.h"
    "Sources/Nacy/Render/Sprite.h"
    "Sources/Nacy/Render/Text.h"
    "Sources/Nacy/Render/Texture.h"
    "Sources/Nacy/Util/Animation/Animation.h"
    "Sources/Nacy/Util/Logger/Logger.h"
    "Sources/Nacy/Util/Utilities.h"
    "Sources/NacyEngine.h"
    "Sources/pch.h"
    "Sources/Nacy/Core/Application.cpp"
    "Sources/Nacy/Core/Event/Event.cpp"
    "Sources/Nacy/Core/GameWindow.cpp"
    "Sources/Nacy/Manager/Assets/ResourceManager.cpp"
    "Sources/Nacy/Manager/Camera/Camera.cpp"
    "Sources/Nacy/Manager/Input/InputManager.cpp"
    "Sources/Nacy/Manager/OpenGL/GLManager.cpp"
    "Sources/Nacy/Manager/Scene/Scene.cpp"
    "Sources/Nacy/Manager/Scene/SceneManager.cpp"
    "Sources/Nacy/Manager/Shader/Shader.cpp"
    "Sources/Nacy/Math/Vector.cpp"
    "Sources/Nacy/Object/GameObject.cpp"
    "Sources/Nacy/Render/Renderer.cpp"
    "Sources/Nacy/Render/Shape.cpp"
    "Sources/Nacy/Render/Sprite.cpp"
    "Sources/Nacy/Render/Text.cpp"
    "Sources/Nacy/Render/Texture.cpp"
    "Sources/Nacy/Util/Animation/Animation.cpp"
    "Sources/Nacy/Util/Logger/Logger.cpp"
    "Sources/Nacy/Util/Utilities.cpp"
    "Sources/pch.cpp"
)


################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${SOURCE})

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/Sources/pch.h>"
)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE NacyEngine)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-${CMAKE_VS_PLATFORM_NAME}/app/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-${CMAKE_VS_PLATFORM_NAME}/app/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Sources;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/Imgui;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/STB;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLM/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/FreeType/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "MAPLE_BUILD_DLL_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "MAPLE_BUILD_DLLNDEBUG"
        ">"
        "_CRT_SECURE_NO_WARNINGS;"
        "NACY_PLATFORM_WINDOW;"
        "NACY_BUILD_DLL;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /std:c++17;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "opengl32;"
        "glfw3;"
        "glew32s;"
        "freetype;"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_SOURCE_DIR}/NacyEngine/Dependencies/FreeType/lib;"
        "${CMAKE_SOURCE_DIR}/NacyEngine/Dependencies/GLFW/lib;"
        "${CMAKE_SOURCE_DIR}/NacyEngine/Dependencies/GLEW/Win32"
    )
endif()


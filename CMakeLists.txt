cmake_minimum_required(VERSION 3.31)
project(MPc C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/raylib)

file(GLOB_RECURSE APP_SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${APP_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/external/raygui/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib) # PRIVATE is usually correct here

# --- Build Configurations ---
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}") # Good to print the selected type

# --- Configure Output Directories based on Build Type ---
set(OUTPUT_BIN_DIR_DEBUG "${CMAKE_BINARY_DIR}/debug/bin")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_BIN_DIR_DEBUG}"
)

# --- Asset Handling ---
# Ensure asset directories exist before trying to copy into them
# Consider creating these directories within the add_custom_command if preferred
file(MAKE_DIRECTORY "${OUTPUT_BIN_DIR_DEBUG}/assets")

# Copy assets using a helper function or directly
# Using a function can make it cleaner if you copy multiple things
function(copy_assets_post_build TARGET_NAME ASSETS_DIR OUTPUT_DIR CONFIG)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "${OUTPUT_DIR}/assets"
        COMMENT "Copying assets to ${CONFIG} bin directory..."
        VERBATIM # Ensures commands are executed as written, important for complex commands
        COMMAND_EXPAND_LISTS # Useful if OUTPUT_DIR contains list variables
    )
endfunction()

# --- Existing Custom Commands (Keep if they work for you) ---
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets" "${OUTPUT_BIN_DIR_DEBUG}/assets"
    COMMENT "Copying assets to debug bin directory..."
    # This command runs unconditionally after build.
    # It might be better to trigger this based on the actual build config.
    # Consider using generator expressions in the COMMAND if possible, or separate targets.
)

add_custom_target(run
    # Quote the entire string for the echo command
    COMMAND ${CMAKE_COMMAND} -E echo "Running Debug version of ${PROJECT_NAME}..."
    COMMAND "$<TARGET_FILE:MPc>"
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY "${OUTPUT_BIN_DIR_DEBUG}"
    USES_TERMINAL
)

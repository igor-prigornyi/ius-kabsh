cmake_minimum_required(VERSION 3.11)

project("ius" C)
set(CMAKE_CC_STANDARD C90)
set(MYCOMPILE_FLAGS "-lm") 

set(SOURCES_DIR "sources")
set(HEADERS_DIR "headers")
set(TYPES_DIR "types")

include_directories("${HEADERS_DIR}")
include_directories("${HEADERS_DIR}/${TYPES_DIR}")

add_compile_options(-Werror=discarded-qualifiers)

add_executable("ius"
               "${SOURCES_DIR}/NVG_Entry_Point.c"
               "${SOURCES_DIR}/NVG_Concept.c"
               "${SOURCES_DIR}/${TYPES_DIR}/T_NVG_Matrix_2x2.c"
               "${SOURCES_DIR}/${TYPES_DIR}/T_NVG_Point_2D.c"
               "${SOURCES_DIR}/${TYPES_DIR}/T_NVG_Coordinate.c"
               "${SOURCES_DIR}/${TYPES_DIR}/T_NVG_Scalar.c")
               
target_link_libraries("ius" m)
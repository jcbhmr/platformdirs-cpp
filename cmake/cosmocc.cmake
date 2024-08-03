# https://jcbhmr.me/blog/cosmocc-cmake
set(CMAKE_SYSTEM_NAME Generic)
unset(CMAKE_SYSTEM_PROCESSOR)
set(CMAKE_ASM_COMPILER cosmocc)
set(CMAKE_C_COMPILER cosmocc)
set(CMAKE_CXX_COMPILER cosmoc++)
set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_LIST_DIR}/cosmocc-override.cmake")
find_program(CMAKE_AR cosmoar REQUIRED)
unset(CMAKE_RANLIB)

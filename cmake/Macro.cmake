macro(bull_set_option variable value type description)
    if(NOT DEFINED ${variable})
        set(${variable} ${value})
    endif()
    set(${variable} ${value} CACHE ${type} ${description} FORCE)
endmacro()

macro(bull_add_library target)
    cmake_parse_arguments(THIS "" "" "SOURCES;DEPENDS;EXTERNALS" ${ARGN})

    add_library(${target} ${THIS_SOURCES})

    if(BUILD_SHARED_LIB)
        if(BULL_OS_WINDOWS)
            set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
            set_target_properties(${target} PROPERTIES SUFFIX "-${CMAKE_SHARED_LIBRARY_SUFFIX}")
        else()
            set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        endif()
        set_target_properties(${target} PROPERTIES PREFIX "")
        set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".dll")
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
        set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -s)
        set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -s)
    endif()

    if(THIS_DEPENDS)
        target_link_libraries(${target} ${THIS_DEPENDS})
    endif()
endmacro()
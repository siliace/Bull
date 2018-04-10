macro(bull_add_library target)
    # create the target
    if(BUILD_SHARED_LIBS)
        add_library(${target} SHARED "")
    else()
        add_library(${target} STATIC "")
    endif()

    if(BULL_OS_WINDOWS)
        # on Windows/gcc get rid of "lib" prefix for shared libraries,
        # and transform the ".dll.a" suffix into ".a" for import libraries
        set_target_properties(${target} PROPERTIES PREFIX "")
        set_target_properties(${target} PROPERTIES IMPORT_PREFIX "")
        set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".a")
    else()
        set_target_properties(${target} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    endif()

    if(BUILD_SHARED_LIBS)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
    endif()
endmacro()
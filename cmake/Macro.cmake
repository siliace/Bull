macro(bull_add_library target)
    # create the target
    if(BUILD_SHARED_LIBS)
        add_library(${target} SHARED "")
    else()
        add_library(${target} STATIC "")
    endif()

    # adjust the output file prefix/suffix to match our conventions
    if(BUILD_SHARED_LIBS)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        if(SFML_OS_WINDOWS)
            # include the major version number in Windows shared library names (but not import library names)
            set_target_properties(${target} PROPERTIES SUFFIX "-${CMAKE_SHARED_LIBRARY_SUFFIX}")
            # on Windows/gcc get rid of "lib" prefix for shared libraries,
            # and transform the ".dll.a" suffix into ".a" for import libraries
            set_target_properties(${target} PROPERTIES PREFIX "")
            set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".a")
        endif()
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
    endif()
endmacro()
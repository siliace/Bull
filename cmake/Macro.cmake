macro(bull_add_library target)
    # create the target
    if(BUILD_SHARED_LIBS)
        add_library(${target} SHARED "")
    else()
        add_library(${target} STATIC "")
    endif()

    if(BUILD_SHARED_LIBS)
        if(BULL_OS_WINDOWS)
            set_target_properties(${target} PROPERTIES PREFIX "")
            set_target_properties(${target} PROPERTIES IMPORT_PREFIX "")
        else()
            set_target_properties(${target} PROPERTIES POSITION_INDEPENDENT_CODE ON)
        endif()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
    endif()

    install(TARGETS ${target}
                ARCHIVE DESTINATION ${BULL_ARCHIVE_INSTALL_PATH}
                LIBRARY DESTINATION ${BULL_LIBRARY_INSTALL_PATH}
                RUNTIME DESTINATION ${BULL_RUNTIME_INSTALL_PATH}
            )
endmacro()
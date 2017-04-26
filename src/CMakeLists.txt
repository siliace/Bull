add_subdirectory(Bull)

add_custom_target(bull)
add_dependencies(bull bull-core)
add_dependencies(bull bull-hardware)
add_dependencies(bull bull-render)
add_dependencies(bull bull-network)
add_dependencies(bull bull-utility)
add_dependencies(bull bull-window)
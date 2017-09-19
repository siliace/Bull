add_subdirectory(Bull)

add_custom_target(bull)
add_dependencies(bull bull-core)
add_dependencies(bull bull-graphics)
add_dependencies(bull bull-network)
add_dependencies(bull bull-render)
add_dependencies(bull bull-system)
add_dependencies(bull bull-utility)

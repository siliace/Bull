add_subdirectory(Bull)

add_custom_target(bull)
add_dependencies(bull bull-core)
add_dependencies(bull bull-graphics)
add_dependencies(bull bull-math)
add_dependencies(bull bull-render)

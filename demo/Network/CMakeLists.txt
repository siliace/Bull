add_subdirectory(Client)
add_subdirectory(Server)

add_custom_target(demo-network)
add_dependencies(demo-network demo-network-client)
add_dependencies(demo-network demo-network-server)

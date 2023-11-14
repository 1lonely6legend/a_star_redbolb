cmake_minimum_required(VERSION 3.23)

project(A_STAR)

set(CMAKE_CXX_STANDARD 17)

add_executable(BFS_SimpleGraph
        BFS/BFS_SimpleGraph.cpp
)

add_executable(BFS_SquareGrid
        BFS/BFS_SquareGrid.cpp
)

add_executable(BFS_EarlyExit
        BFS/BFS_EarlyExit.cpp
)

add_executable(Dijkstra
        Dijkstra/Dijkstra.cpp
)

add_executable(a_star
        a_star/a_stat.cpp
)

add_executable(Dijkstra_NoPath
        Dijkstra/Dijkstra_NoPath.cpp
)

add_executable(Dijkstra_DistanceFields
        Dijkstra/Dijkstra_DistanceFields.cpp
)
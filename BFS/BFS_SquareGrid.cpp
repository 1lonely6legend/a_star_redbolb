//
// Created by ogier on 2023/11/13.
//
#include"../implementation.cpp"
using namespace std;

template<typename Location, typename Graph>
unordered_map<Location, Location> breadth_first_search(Graph graph, Location start) {
  //遍历查找的区域边界数组
  queue<Location> frontier;
  frontier.push(start);
  //存储遍历过的数组,并且记录上一个节点
  unordered_map<Location, Location> came_from;
  came_from[start] = start;//起始点的上一个还是定义为起始点

  while (!frontier.empty()) {
    Location current = frontier.front();
    frontier.pop();

    for (Location next : graph.neighbors(current)) {
      if (came_from.find(next) == came_from.end()) {
        frontier.push(next);
        came_from[next] = current;
      }
    }
  }
  return came_from;
}

int main() {
  SquareGrid grid = make_diagram1();
  GridLocation start{7,8};
  auto parents = breadth_first_search(grid,start);
  draw_grid(grid, nullptr,&parents, nullptr,&start);
  return 0;
}

//
// Created by ogier on 2023/11/13.
//
//相比较于BFS多添加一个判断条件,并且需要指定一个目标,而不是遍历完所有节点
#include"../implementation.cpp"
using namespace std;

template<typename Location, typename Graph>
unordered_map<Location, Location> breadth_first_search(Graph graph, Location start, Location goal) {
  //遍历查找的区域边界数组
  queue<Location> frontier;
  frontier.push(start);
  //存储遍历过的数组,并且记录上一个节点
  unordered_map<Location, Location> came_from;
  came_from[start] = start;//起始点的上一个还是定义为起始点

  while (!frontier.empty()) {
    Location current = frontier.front();
    frontier.pop();

    ////////////////////
    if (current == goal) {
      break;
    }
    ////////////////////


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
  GridLocation start{8, 7}, goal{17, 2};
  auto parents = breadth_first_search(grid, start, goal);
  draw_grid(grid, nullptr, &parents, nullptr, &start, &goal);
  return 0;
}

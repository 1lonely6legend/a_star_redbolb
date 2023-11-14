//
// Created by ogier on 2023/11/13.
//
#include"../implementation.cpp"
using namespace std;

template<typename Location, typename Graph>
//搜索算法
void dijkstra_search(Graph graph, Location start, Location goal,
                     unordered_map<Location, Location> &came_from,
                     unordered_map<Location, Location> &cost_so_far) {
  //使用一个优先级队列,从小到大,存放需要遍历的边缘节点以及其 走过的路程代价
  PriorityQueue<Location, double> frontier;
  frontier.put(start, 0);
  came_from[start] = start;
  cost_so_far[start] = 0;

  while (!frontier.empty()) {
    Location current = frontier.get();

    if (current == goal) break;

    for (Location next : graph.neighbors(current)) {
      double new_cost = cost_so_far[current] + graph.cost(current, next);
      //如果还没有遍历过,或者找到代价更小的路,需要更新.  注意需要先判断是否存在,避免访问cost_so_far[next]出错
      if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next])
        cost_so_far[next] = new_cost;
      came_from[next] = current;
      frontier.put(next, new_cost);
    }
  }
}

int main() {
  GridWithWeights grid = make_diagram_nopath();
  GridLocation start{1, 4}, goal{8, 3};
  std::unordered_map<GridLocation, GridLocation> came_from;
  std::unordered_map<GridLocation, double> cost_so_far;
  dijkstra_search(grid, start, goal, came_from, cost_so_far);
  draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);
  reconstruct_path(start, goal, came_from);
}
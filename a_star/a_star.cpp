//
// Created by ogier on 2023/11/13.
//
#include"../implementation.cpp"
using namespace std;

double heuristic(GridLocation a, GridLocation b) {
  //设定启发式函数为曼哈顿函数.保证估计路程小于等于
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

template<typename Location, typename Graph>
void a_star_search
    (Graph graph,
     Location start,
     Location goal,
     std::unordered_map<Location, Location>& came_from,
     std::unordered_map<Location, double>& cost_so_far)
{
  PriorityQueue<Location, double> frontier;
  frontier.put(start, 0);

  came_from[start] = start;
  cost_so_far[start] = 0;

  while (!frontier.empty()) {
    Location current = frontier.get();

    if (current == goal) {
      break;
    }

    for (Location next : graph.neighbors(current)) {
      double new_cost = cost_so_far[current] + graph.cost(current, next);
      if (cost_so_far.find(next) == cost_so_far.end()
          || new_cost < cost_so_far[next]) {
        cost_so_far[next] = new_cost;
        double priority = new_cost + heuristic(next, goal);
        frontier.put(next, priority);
        came_from[next] = current;
      }
    }
  }
}

int main(){
  GridWithWeights grid = make_diagram4();
  GridLocation start{1,4},goal{8,3};
  unordered_map<GridLocation,GridLocation>came_from;
  unordered_map<GridLocation,double>cost_so_far;
  a_star_search(grid,start,goal,came_from,cost_so_far);
  draw_grid(grid, nullptr,&came_from, nullptr,&start,&goal);
  cout<<endl;
  vector<GridLocation> path = reconstruct_path(start, goal, came_from);
  draw_grid(grid, nullptr, nullptr, &path, &start, &goal);
  cout << '\n';
  draw_grid(grid, &cost_so_far, nullptr, nullptr, &start, &goal);
}
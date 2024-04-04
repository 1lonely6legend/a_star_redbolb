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
  //首先初始化一个最小堆
  PriorityQueue<Location, double> frontier;
  //将起点放入堆中代价为0
  frontier.put(start, 0);

  //在两个map中记录起点的信息
  came_from[start] = start;
  cost_so_far[start] = 0;

  //当堆不为空时
  while (!frontier.empty()) {
    //取出堆顶元素
    Location current = frontier.get();
    //如果当前位置是终点,则退出循环
    if (current == goal) {
      break;
    }
    //遍历当前位置的邻居
    for (Location next : graph.neighbors(current)) {
      //计算新的代价,考虑图上的权重
      double new_cost = cost_so_far[current] + graph.cost(current, next);
      //如果新的代价小于之前的代价,或者之前没有记录过这个位置
      if (cost_so_far.find(next) == cost_so_far.end()
          || new_cost < cost_so_far[next]) {
        //更新代价和路径
        cost_so_far[next] = new_cost;
        //计算cost和启发式函数的和作为优先级
        double priority = new_cost + heuristic(next, goal);
        //更新堆
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
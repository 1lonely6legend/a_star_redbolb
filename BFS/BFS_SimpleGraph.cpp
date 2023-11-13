//
// Created by ogier on 2023/11/13.
//
#include"../implementation.cpp"

void breadth_first_search(SimpleGraph graph, char start) {
  //入参为搜索的地图和起点

  // 当前可以搜索的点,边界,使用队列,先入先出
  std::queue<char> frontier;
  frontier.push(start);

  // 搜索过的点
  std::unordered_set<char> reached;
  reached.insert(start);

  while (!frontier.empty()) {
    //while中依次取出边界上需要遍历的点
    char current = frontier.front();
    frontier.pop();

    std::cout << "Visiting " << current << std::endl;
    //遍历当前节点的所有相邻节点,如果还没有访问过,就加入queue和set中
    for(auto next:graph.neighbors(current)){
      if(reached.find(next)==reached.end()){
        frontier.push(next);
        reached.insert(next);
      }
    }
  }
}

int main(){

  //一个地图的样本
  SimpleGraph example_graph{{
                                {'A', {'B'}},
                                {'B', {'C'}},
                                {'C', {'B', 'D', 'F'}},
                                {'D', {'C', 'E'}},
                                {'E', {'F'}},
                                {'F', {}},
                            }};

  std::cout << "Reachable from A:\n";
  breadth_first_search(example_graph, 'A');
  std::cout << "Reachable from E:\n";
  breadth_first_search(example_graph, 'E');
}
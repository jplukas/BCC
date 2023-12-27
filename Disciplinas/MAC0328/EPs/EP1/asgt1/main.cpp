#include <iostream>
#include <boost/range/iterator_range.hpp> // for boost::make_iterator_range
#define BOOST_ALLOW_DEPRECATED_HEADERS // silence warnings
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define RED 3
#define PURPLE 4
#define PINK 5

#include <stack>

struct BundledVertex {
  int color;
  int pre; //predecessor
  // int discovery;
  // int finishing;
};



typedef boost::adjacency_list<boost::vecS,
                              boost::vecS,
                              boost::directedS,
                              BundledVertex>
                              Graph;

typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

int normaliza(int t, int n){
  int r = t - n;
  if (r >= 0) r++;
  return r;
}

int dfs(Graph& g, int n, Vertex u){
  int m = (n + 1) / 2;
  int s = (((int)u) - m);
  if (s >= 0) s++;
  // std::cout << "DFS " << s << std::endl;

  switch(g[u].color){
    case WHITE:
      
      g[u].color = GRAY;
      g[n - ((int)u)].color = PINK;
      break;
    case PINK:
      
      g[u].color = GRAY;
      g[n - ((int)u)].color = RED;
      break;
    case RED:

      return u;
      break;
    default:
      break;
  }

  for(const auto& t : boost::make_iterator_range(boost::vertices(g))){
    int show = (((int)t) - m);
    if (show >= 0 )show++;
    // std::cout << show << " "; 
    switch (g[t].color){
      case WHITE:
        // std::cout << "WHITE";
        break;
      
      case GRAY:
        // std::cout << "GRAY";
        break;

      case BLACK:
        // std::cout << "BLACK";
        break;

      case RED:
        // std::cout << "RED";
        break;

      case PURPLE:
        // std::cout << "PURPLE";
        break;

      case PINK:
        // std::cout << "PINK";
        break;

      default:
        // std::cout << "ERROR";
        break;
      }
      // std::cout << std::endl;
    }
    // std::cout << std::endl;

  for(const auto& adj : boost::make_iterator_range(boost::out_edges(u, g))){
    Vertex v = adj.m_target;
    int show = (((int)v) - m);
    if (show >= 0 )show++;
    // std::cout << "Em " << s << "; considerando " << show << std::endl;
    switch (g[v].color){
    case WHITE:
      // std::cout << "WHITE" << std::endl;
      g[v].pre = u;
      if(dfs(g, n, v) >= 0) return v;
      break;
    
    case RED:
      // std::cout << "RED" << std::endl;
      g[v].pre = u;
      if(dfs(g, n, v) >= 0) return v;
      break;

    case PINK:
      // std::cout << "PINK" << std::endl;
      g[v].pre = u;
      if(dfs(g, n, v) >= 0) return v;
      break;

    case GRAY:
      // std::cout << "GRAY" << std::endl;
      break;

    case PURPLE:
      // std::cout << "PURPLE" << std::endl;
      break;

    case BLACK:
      // std::cout << "BLACK" << std::endl;
      break;

    default:
      // std::cout << "UNKNOWN" << std::endl;
      break;
    }
  }
  if(g[u].color == GRAY){
    g[u].color = BLACK;
    g[n - ((int)u)].color = PURPLE;
  }
  if(g[u].color == RED) g[u].color = PURPLE;
  // std::cout << "Terminando " << s << ". Cor final: " << g[u].color << std::endl; 
  return -1;
}

void dfs_wrapper(Graph& g, int n){
  bool found = false;
  for(const auto& u : boost::make_iterator_range(boost::vertices(g))){
    int show = (((int)u) - n);
    if (show >= 0 )show++;
    //  std::cout << "considerando " << show << std::endl;
    if(g[u].color == WHITE){
      int t = (dfs(g, (2 * n - 1), u));
      if(t >= 0){
        std::cout << "NO" << std::endl;
      if(t >= n) t -= n;
      std::cout << normaliza(t + n, n) << std::endl;
      Vertex pre = g[t].pre;
      std::stack<int> q;
      q.push(t);
      while(pre != (t + n)){
        q.push(pre);
        pre = g[pre].pre;
      }
      q.push(pre);
      std::cout << q.size() - 1 << " ";

      while(!q.empty()){
        std::cout << normaliza(q.top(), n) << " ";
        q.pop();
      }
      std::cout << std::endl;

      while(pre != t){
        q.push(pre);
        pre = g[pre].pre;
      }
      q.push(pre);

      std::cout << q.size() - 1 << " ";

      while(!q.empty()){
        std::cout << normaliza(q.top(), n) << " ";
        q.pop();
      }
      std::cout << std::endl;

      found = true;
      break;
    }
    }  
  }
  if (!found){
    std::cout << "YES" << std::endl;
    for(int i = n; i < 2 * n; i++)
      std::cout << (g[i].color == BLACK ? 1 : 0) << " "; 
  std::cout << std::endl;
  for(const auto& u : boost::make_iterator_range(boost::vertices(g))){
    int show = (((int)u) - n);
    if (show >= 0 )show++;
    // std::cout << show << " "; 
    switch (g[u].color){
      case WHITE:
        // std::cout << "WHITE";
        break;
      
      case GRAY:
        // std::cout << "GRAY";
        break;

      case BLACK:
        // std::cout << "BLACK";
        break;

      case RED:
        // std::cout << "RED";
        break;

      case PURPLE:
        // std::cout << "PURPLE";
        break;

      case PINK:
        // std::cout << "PINK";
        break;


      default:
        // std::cout << "ERROR";
        break;
      }
      // std::cout << std::endl;
    }
  }
}


int main(int argc, char** argv){
  int d; std::cin >> d;
  typename boost::graph_traits<Graph>::vertices_size_type n; std::cin >> n;
  Graph graph(2 * n);
  size_t m; std::cin >> m;

  while (m--) {
    int u, v; std::cin >> u >> v;

    if(u < 0) u += n;
    else u += n - 1;

    if(v < 0) v += n;
    else v += n - 1; 

    u = ((2 * n) - 1) - u;

    boost::add_edge(u, v, graph);
    u = ((2 * n) - 1) - u;
    v = ((2 * n) - 1) - v;
    boost::add_edge(v, u, graph);
  }

  for(const auto& i : boost::make_iterator_range(boost::vertices(graph)))
    graph[i].color = WHITE;


  dfs_wrapper(graph, n);
  return EXIT_SUCCESS;
}

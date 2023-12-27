#include "asgt.h"
#include <vector>
#include <stack>

void algo(Graph &g);
void algo_visit(Graph &g, Vertex v, std::stack<Edge> &st, int &time, int &nbccs);

void compute_bcc (Graph &g, bool fill_cutvxs, bool fill_bridges)
{
  /* fill everything with dummy values */
  for (const auto& vertex : boost::make_iterator_range(boost::vertices(g))) {
    g[vertex].cutvertex = false;
    g[vertex].color = WHITE;
    g[vertex].discovery = -1;
  }

  for (const auto& edge : boost::make_iterator_range(boost::edges(g))) {
    g[edge].bcc = 0;
    g[edge].bridge = false;
    g[edge].visited = false;
  }
  algo(g);
}

void algo (Graph &g){
  int nbccs = 0;
  std::stack<Edge> st;
  int time = 0;
  for (const auto& vertex : boost::make_iterator_range(boost::vertices(g))) {
    if(g[vertex].color == WHITE){
      algo_visit(g, vertex, st, time, nbccs);
    }
  }
}

void algo_visit(Graph &g, Vertex v, std::stack<Edge> &st, int &time, int &nbccs){
  g[v].color = GRAY;
  g[v].discovery = ++time;
  g[v].lowpoint = g[v].discovery;
  int lowpoint = g[v].lowpoint;
  int tree_edges = 0;
  for(const auto& edge : boost::make_iterator_range(boost::out_edges(v, g))){
    if(! g[edge].visited){
      g[edge].visited = true;
      st.push(edge);
      Vertex tgt = edge.m_target;
      if (v == tgt)
        tgt = edge.m_source;
      int low = 0;
      if(g[tgt].color == WHITE){
        //tree edge
        g[edge].tree = true;
        tree_edges++;
        algo_visit(g, tgt, st, time, nbccs);
        low = g[tgt].lowpoint;
      }
      else{
        //back edge
        g[edge].tree = false;
        low = g[tgt].discovery;
      }
      //backtrack
      if(low < lowpoint) lowpoint = low;
      if(low >= g[v].lowpoint){
        //v is a "base" of a bcc

        if(low > g[v].lowpoint) g[v].cutvertex = true;
        else{
          //root of the dfs
          if(tree_edges > 1) g[v].cutvertex = true;
        }
        
        nbccs++;
        Edge e;
        int count = 0;
        while (! st.empty()){
          e = st.top();
          st.pop();
          count++;
          g[e].bcc = nbccs;
          if((e.m_source == v || e.m_target == v) && g[e].tree) break;
        }
        if(count == 1){
          g[e].bridge = true;
        }
      }
    }
  }
  g[v].color = BLACK;
  g[v].lowpoint = lowpoint;
}
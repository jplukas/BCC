/* This is the main file that the students must work on to submit; the
 * other one is arb.h
 */

#include "asgt.h"

Arb read_arb(std::istream& in)
{
  size_t n; in >> n;
  Arb arb(n--);

  while (n--) {
    int u, v; in >> u >> v;
    // std::cout << "(" << u << ", " << v << ")" << std::endl;
    boost::add_edge(--u, --v, arb);
  }
  return arb;
}

void dfs(Arb &arb, const Vertex& v, HeadStart &h){
  static int time = 1;
  if(h.times[v].first == 0){ //vertice nao descoberto{
    h.times[v].first = time++;
    for(const auto& e : boost::make_iterator_range(boost::out_edges(v, arb)))
      dfs(arb, e.m_target, h);
    h.times[v].second = time++;
  } 
}

HeadStart preprocess (Arb &arb, const Vertex& root)
{
  int n_vertices = boost::num_vertices(arb);
  HeadStart h(n_vertices);
  dfs(arb, root, h);
  return h;
}

bool is_ancestor (const Vertex& u, const Vertex& v, const HeadStart& data)
{
  return (data.times[u].first <= data.times[v].first) && (data.times[u].second >= data.times[v].second);
}

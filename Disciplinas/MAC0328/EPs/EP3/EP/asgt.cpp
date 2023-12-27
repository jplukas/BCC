#include "asgt.h"

#include <utility>              // for std::get
#include <tuple>
#include <vector>
#include <queue>
#include <limits>

#define BOOST_ALLOW_DEPRECATED_HEADERS // silence warnings
#include <boost/graph/adjacency_list.hpp>
#include <boost/optional.hpp>

#include "cycle.h"
#include "digraph.h"
#include "potential.h"

/* The code in this template file is all "bogus". It just illustrates
 * how to return answers back to main.cpp. */

/* The following declarations shorten the bogus code below. Feel free
 * to change/drop them. */
using boost::add_edge;
using boost::num_vertices;
using boost::out_edges;
using std::vector;

Digraph build_digraph(const Digraph& market)
{
  std::cout << "build_digraph" << std::endl;
  /* placeholder for NRVO */
  Digraph digraph(num_vertices(market));
  for (const auto& edge : boost::make_iterator_range(boost::edges(market))){
    auto v_source = edge.m_source;
    auto v_target = edge.m_target;
    Arc a;
    std::tie(a, std::ignore) = add_edge(v_source, v_target, digraph);
    digraph[a].cost = - log2(market[edge].cost);
  }
  for (const auto& vertex : boost::make_iterator_range(boost::vertices(digraph))){
    digraph[vertex].relax = false;
    digraph[vertex].visited = false;
  }
  
  return digraph;
}

std::tuple<bool,
           boost::optional<NegativeCycle>,
           boost::optional<FeasiblePotential>>
has_negative_cycle(Digraph& digraph)
{
  std::cout << "entrou" << std::endl;
  int n_vertices = num_vertices(digraph);
  for (const auto& source : boost::make_iterator_range(boost::vertices(digraph))){
    if(! digraph[source].visited){
      digraph[source].visited = true;
      vector<vector<Arc>> W(n_vertices);
      double mmax = std::numeric_limits<double>::max();
      vector<double> d(n_vertices, mmax);
      vector<int> c(n_vertices, 0);
      d[source] = 0.0;
      std::queue<Vertex> q;
      digraph[source].relax = true;
      q.push(source);
      std::cout << "source: " << source << std::endl;
      while(! q.empty()){
        Vertex u = q.front();
        q.pop();
        digraph[u].relax = false;
        // std::cout << "u: " << u << std::endl;
        for (const auto& adj_arc : boost::make_iterator_range(boost::out_edges(u, digraph))){
          std::cout << adj_arc << ": " << digraph[adj_arc].cost << std::endl;
          Vertex v = adj_arc.m_source == u ? adj_arc.m_target : adj_arc.m_source;
          digraph[v].visited = true;
          double new_cost = d[u] + digraph[adj_arc].cost;
          if(d[v] > new_cost){
            d[v] = new_cost;
            W[v] = W[u];
            W[v].push_back(adj_arc);
            if(! digraph[v].relax){
              digraph[v].relax = true;
              q.push(v);
              c[v]++;
              std::cout << v << ": " << c[v] << std::endl;
              if(c[v] > n_vertices || v == source){
                //Cycle detected
                std::cout << "Ciclo:" << std::endl;
                std::cout << "start: " << v << std::endl;
                Walk wlk(digraph, v);
                for (const Arc& v_i : W[v]){
                  // std::cout << v_i << std::endl;
                  wlk.extend(v_i);
                  // std::cout << wlk;
                  if(wlk.is_cycle()) return {true, NegativeCycle(wlk), boost::none};
                }
              }
            }
          }
        }
          std::cout << "q size: " << q.size() << std::endl;
        // std::cout << "d: " << std::endl;
        // for(const auto& v : d){
        //   std::cout << v << std::endl;
        // }
      }
    }
  }
  // const Arc& a0 = *(out_edges(0, digraph).first);
  // const Arc& a1 = *(out_edges(1, digraph).first);

  // Walk walk(digraph, 0);
  // walk.extend(a0);
  // walk.extend(a1);

  /* Replace `NegativeCycle(walk)` with `boost::none` in the next
   * command to trigger "negative cycle reported but not computed".
   * Comment the whole `return` and uncomment the remaining lines to
   * exercise construction of a feasible potential. */

  // encourage RVO

  /* Replace `FeasiblePotential(digraph, y)` with `boost::none` in the
   * next command to trigger "feasible potential reported but not
   * computed". */

  // encourage RVO
  vector<double> y(num_vertices(digraph), 0.0);
  return {false, boost::none, FeasiblePotential(digraph, y)};
}

Loophole build_loophole(const NegativeCycle& negcycle,
                        const Digraph& aux_digraph,
                        const Digraph& market){
  vector<Arc> arcs = negcycle.get();
  const Vertex& start = arcs[0].m_source;
  Walk w(market, start);
  for(const auto& arc : arcs){
    auto u = arc.m_source;
    auto v = arc.m_target;
    auto m_arc = boost::edge(u, v, market).first;
    w.extend(m_arc);
  }
  

  // encourage RVO
  return Loophole(w);
}

FeasibleMultiplier build_feasmult(const FeasiblePotential& feaspot,
                                  const Digraph& aux_digraph,
                                  const Digraph& market)
{
  vector<double> z(num_vertices(market), 1.0);

  // encourage RVO
  return FeasibleMultiplier(market, z);
}

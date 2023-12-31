/* the definition of HeadStart may be changed in this file; the rest
 * MUST NOT be changed
 */

#ifndef ARB_H
#define ARB_H

#define BOOST_ALLOW_DEPRECATED_HEADERS // silence warnings
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <vector>
using std::vector;
using std::pair;

typedef boost::adjacency_list<boost::vecS,
                              boost::vecS,
                              boost::directedS> Arb;
typedef boost::graph_traits<Arb>::vertex_descriptor Vertex;
typedef pair<int, int> Disc_Fin;

/* Students must adapt this class for their needs; the innards of
   these objects are only accessed by the student's code */
class HeadStart {
public:
  HeadStart(int n) : n_vertices(n) {
    times.resize(n);
  }
  vector<Disc_Fin> times;
private:
  int n_vertices;
};

#endif // #ifndef ARB_H

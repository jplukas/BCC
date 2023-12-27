# Graph Algorithms
## Overview
### 1. Digraphs
A ***digraph*** is an ordered pair $D = (V, A)$, where $V$ is a set of $n$ ***vertices*** and $A$ is a set of $m$ ***arcs***. Each arc is an ordered pair of vertices (from $V$). Usually, $n$ and $m$ are parameters to measure running time of algorithms.

#### Terminology
If $u,v \in V$ are vertices, and there is an arc $a = (u, v) \in A$, we say that $a$ *leaves* $u$ and *enters* $v$, and $u$ is the *tail* of $a$ and $v$ is its *head*. We can also abbreviate the notation for the arc $(u, v)$ as $uv$.
A ***loop*** is an arc whose tail and head are coincident. We say that two arcs $uv$ and $vu$ are ***anti-parallel***.

### 2. Graphs
A ***graph*** is an ordered pair $G = (V, E)$, where $V$ is a set of ***vertices***, and $E$ is a set of ***edges***. Each edge is an unordered pair of vertices from $V$ (that is, a subset of size 2 of $V$).
As with digraphs, we also abbreviate the notation from an edge $\{u, v\}$ as simply $uv$.

#### Terminology
If $u, v \in V$ are vertices and there is an edge $e$ that connects $u$ and $v$, we say that $u$ and $v$ are *adjacent* or *neighbours*, and $u$ and $v$ are the *ends* of $e$, or that $u$ and $v$ are *incidental* with $e$, or even that $e$ *joins* $u$ and $v$.

**Attention: although they share a lot of similarities, graphs and digraphs are different.** Digraphs have *arcs*, graphs have *edges*. Also, we prohibit graphs with loops, and if an edge connects the vertices $u$ and $v$, we can write said edge as $uv$ as well as $vu$.


### 3. This course
#### What is this course about?
- Algorithm design (implementation, correctness, complexity, running time...)
- A programming lab for graph algorithms and data structures

#### What is this course *not* about?
- Graph theory
- Fully detailed proofs
- Our chosen programming language (in this case, ***C++***)


### 4. Computer representations
For a given vertex set $V$ of size $n$, assume $V = \{1, 2, \dots, n\}$ (or $V = \{0, 1, \dots, n - 1\}$, in the source code).
Most of the time, we may represent a graph $G = (V, E)$ as the *symmetric* digraph $D = \left(V, \bigcup\limits_{\{u, v\} \in V}\{(u, v), (v, u)\}\right)$.

#### Usual operations in graph algorithms
- Determine if two vertices are joined by an arc/edge
- Traverse, for a given vertex $v$, all the arcs that leave/enter $v$

#### 1. Adjacency matrix
Represent $D = (V, A)$ by an $n \times n$ matrix $M$ with
$$
m_{uv} =
\begin{cases}
1 & \text{if } uv \in A\\
0 & \text{otherwise}
\end{cases}
$$

#### 2. Adjacency lists
Represent $D = (V, A)$ by an array $\textbf{Adj}[1, \dots, n]$ of $n$ linked lists, where $\textbf{Adj}[u]$ is a linked list of the arcs that leave $u$ (more explicitly, the entries of the linked list are *heads* of the arcs that leave $u$).

#### 3. "Adjacency arrays"
$D = (V, A)$ by an array $\textbf{Adj}[1, \dots, n]$ of $n$ **arrays**, where $\textbf{Adj}[u]$ is an **array** (or even, a ***sub-array***) of the arcs that leave $u$, together with an array $\textbf{sizes}[1, \dots, n]$ that holds the sizes of the sub-arrays. So, for graphs, the entry $\textbf{sizes}[u]$ of the adjacency array representation of a graph contains the degree of that vertex $u$, while for a digraph, the entry represents the *outdegree* of vertex $u$.


### Comparison between computer representations
|comparison|adjacency matrix|adjacency lists/arrays|
|----------|----------------|----------------------|
|space     |$\theta(n^2)$|$\theta(n + m)$|
|empty initialization|$\theta(n^2)$|$\theta(n)$|
|traverse arcs leaving vertex $u$ for all $u$s|$\theta(n^2)$|$\theta(n + m)$|
|edge/arc between $u$ and $v$?|$\theta(1)$|$\mathcal{O}(n)$|


# The Boost Graph Library (BGL)
In this course, we will be using C++ 11/14/17, together with the Boost Graph Library.

## Building a digraph
### Initializing an empty digraph
Let's build a digraph. First, we must choose the representation type we are going to use to store our digraph. In this case, we are going to use an [[main.md#4. Computer representations | adjacency array]] representation.


```C++
 // create the Digraph type
  typedef boost::adjacency_list<boost::vecS, // std::vectors for arcs on each vertex
                                boost::vecS, // std::vector for vertices
                                boost::directedS> Digraph;
```

To initialize an empty digraph, we must tell its constructor its number of vertices:
```C++
  typename boost::graph_traits<Digraph>::vertices_size_type num_vertices = 5;
  // int num_vertices = 5; // alternatively, this also works

  // Construct a digraph with no arcs
  Digraph digraph(num_vertices);
```

### Adding arcs
Now we must add the arcs.
```C++
// add arcs; vertex numbers are in the half-open range [0,num_vertices)
  boost::add_edge(0, 1, digraph);
  boost::add_edge(0, 2, digraph);
  boost::add_edge(1, 2, digraph);
  boost::add_edge(2, 0, digraph);
  boost::add_edge(3, 1, digraph);
  boost::add_edge(3, 2, digraph);
  boost::add_edge(3, 4, digraph);
  boost::add_edge(4, 0, digraph);
  boost::add_edge(4, 4, digraph);

  /*
  // alternatively, hardcode vertices in [1,num_vertices] in an array
  std::array<std::pair<int, int>, 9> arcs { {
                                             {1, 2},
                                             {1, 3},
                                             {2, 3},
                                             {3, 1},
                                             {4, 2},
                                             {4, 3},
                                             {4, 5},
                                             {5, 1},
                                             {5, 5} } };

  for (const auto& arc: arcs) {
    boost::add_edge(arc.first - 1, arc.second - 1, digraph);
  }
  */
```

### Building a digraph already with arcs
Alternatively, we can build a digraph already with all its arcs. For this, we simply pass the digraph constructor a pair of iterators for an array of arcs, and a number of vertices.

```C++
 typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS> Digraph;

  typename boost::graph_traits<Digraph>::vertices_size_type num_vertices = 5;

  // hardcode vertices in [1,num_vertices] in an array
  std::array<std::pair<int, int>, 9> arcs { { {1, 2},
                                              {1, 3},
                                              {2, 3},
                                              {3, 1},
                                              {4, 2},
                                              {4, 3},
                                              {4, 5},
                                              {5, 1},
                                              {5, 5} } };

  for (auto& a : arcs) {
    --a.first;
    --a.second;
  }

  // Construct a digraph with arcs
  Digraph digraph(arcs.cbegin(), arcs.cend(), num_vertices);
```

In this example, `arcs` is our array of arcs, `arcs.cbegin()` is an iterator for the first element of the array `arcs`, and `arcs.cend()` is an iterator for one past the last element of `arcs`.

## Traversing a digraph
For traversing a digraph, we can simply list all arcs (or all arc heads) that leave a vertex $u$, for all vertices in the digraph.\
In this example, we use the function `boost::make_iterator_range` that allows us to use range-based for loops.
```C++
  using boost::make_iterator_range;
  for (const auto& vertex : make_iterator_range(boost::vertices(digraph))) {
    std::cout << "Arcs that leave " << vertex + 1 << " go to:";
    for (const auto& arc : make_iterator_range(boost::out_edges(vertex, digraph))) {
      std::cout << " " << boost::target(arc, digraph) + 1;
    }

    std::cout << std::endl;
  }
```

## Building a digraph from standard input

```C++
Digraph read_digraph (std::istream& in)
{
  typedef typename boost::graph_traits<Digraph>::vertices_size_type vertices_size_type;
  vertices_size_type num_vertices; in >> num_vertices;

  size_t num_arcs; in >> num_arcs;

  // accumulate all data before digraph construction
  std::vector<std::pair<int, int> > arcs;
  while (num_arcs--) {
    int u, v; in >> u >> v;
    arcs.push_back(std::make_pair(--u, --v));
  }

  // guarantees copy elision in c++17
  return Digraph(arcs.cbegin(), arcs.cend(), num_vertices);
}

int main (int argc, char** argv)
{
  Digraph digraph = read_digraph(std::cin);

  typedef boost::graph_traits<Digraph>::vertex_iterator vertex_iter_type;
  vertex_iter_type vertex_it, vertex_end;

  using boost::make_iterator_range;
  for (const auto& vertex : make_iterator_range(boost::vertices(digraph))) {
    std::cout << "Arcs that leave " << vertex + 1 << " go to:";
    for (const auto& arc : make_iterator_range(boost::out_edges(vertex, digraph))) {
      std::cout << " " << boost::target(arc, digraph) + 1;
    }

    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
```


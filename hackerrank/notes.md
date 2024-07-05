# NOTES
## SBU Campus Network
Link: https://www.hackerrank.com/contests/sbu-icpc-selection-contest-2023/challenges/robustness-test

Reference: https://codeforces.com/blog/entry/71146
### Strong Connected Components
In the directed graph, SCCs are maximal subgraph that every node can reach other nodes within the subgraph.

Example: Graph A(SCC) & Graph B(non-SCC).
```plaintext
   Graph A         Graph B
    1 → 2
    ↑   ↓          1 → 2 → 3
    3 ← 4
```

### Articulation Points(Cut Vertices)
The articulation point in a graph is a vertex that, when removed, the connected components in a graph will be increased. Or you can say, it is like a critical friend in a group that connects different friend circles. If this friend leaves, the group breaks into smaller groups that can't reach each other anymore.

#### How to find articulation points in a graph?
In the naive way, it costs O(V* (V+E)).
```plaintext
For every vertex V in the graph G do
  Remove V from G
  if (the number of connected components increases) then V is an articulation point
  Add V back to G
```
### Tarjan Algorithm

#### Idea
In Tarjan Alogorithm, it only cost O(V+E) by using DFS and stack.

Let's say there is a node 𝑉 in some graph 𝐺 that can be reached by a node 𝑈 through some intermediate nodes (maybe non intermediate nodes) following some DFS traversal, if 𝑉 can also be reached by 𝐴 = "ancestor of 𝑈" without passing through 𝑈 then, 𝑈 is NOT an articulation point because it means that if we remove 𝑈 from 𝐺 we can still reach 𝑉 from 𝐴, hence, the number of connected components will remain the same.

If a node V is the articulation points, it has to satisfy one of the following conditions:

1.If all paths from 𝐴 to 𝑉 require 𝑈 to be in the graph. In other words, there is no side path for V to get to A.

```plaintext
A->U->V
```

2.If 𝑈 is the root of the DFS traversal with at least 2 children subgraphs disconnected from each other. 

#### Implementation

Firstly, we need to know who is the ancestor. By using DFS and assign *discovery time* for each vertex, we can know exactly each node's ancestor.

For example, for graph A->B->C, for node A, B, C, the discovery time is 1, 2, 3. Obviously, A is the ancestor of B and C since discovery_time[A] < discovery_time[B] and discovery_time[A] < discovery_time[C].

Then we can translate the two conditions above. For a node U,
1. If there is no way to get to node V with strictly smaller discovery time than the discovery time of 𝑈 following the DFS traversal, then 𝑈 is an articulation point. (it has to be strictly because if it is equal it means that 𝑈 is the root of a cycle in the DFS traversal which means that 𝑈 is still an articulation point).
2. If 𝑈 is the root of the DFS tree and it has at least 2 children subgraphs disconnected from each other, then 𝑈 is an articulation point.

So, for implementation details, we will think of it as if for every node 𝑈 we have to find the node 𝑉 with the least discovery time that can be reached from 𝑈 following some DFS traversal path which does not require to pass through any already visited nodes, and let's call this node 𝑙𝑜𝑤.

Then, we can know that 𝑈 is an articulation point if the following condition is satisfied: discovery_time[U] <= low[V] ( 𝑉 in this case represents an adjacent node of 𝑈 ).

#### Example Codes in C++
```C++
// adj[u] = adjacent nodes of u
// ap = AP = articulation points
// p = parent
// disc[u] = discovery time of u
// low[u] = 'low' node of u

int dfsAP(int u, int p) {
  int children = 0;
  low[u] = disc[u] = ++Time;
  for (int& v : adj[u]) {
    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
    if (!disc[v]) { // if V has not been discovered before
      children++;
      dfsAP(v, u); // recursive DFS call
      if (disc[u] <= low[v]) // condition #1
        ap[u] = 1;
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    } else // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
  }
  return children;
}

void AP() {
  ap = low = disc = vector<int>(adj.size());
  Time = 0;
  for (int u = 0; u < adj.size(); u++)
    if (!disc[u])
      ap[u] = dfsAP(u, u) > 1; // condition #2
}
```

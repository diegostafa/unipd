## graph

terminology:
* V --> set of verts (usually just numbers, 1..n)
* E --> set of edges (pairs of verts)
* n = number of verts
* m = number of edges
* incident edge --> edge between 2 verts
* adjacent vert --> vert which has an incident edge to another vert
* neighbors --> all verts adjacent to v
* d(v) --> degrees --> number of incident edges(edges in which v is present)
* opposite(v, E) --> opposite vert to v on the edge E
* matching edges --> edges that don't share verts
* perfect matching --> matching which touches all verts
* maximal matching --> matching the most possible amount of edges
* maximum matching --> matching with the largest amount of edges (maximum is always also the maximal, the opposite is not true)
* simple path --> path of distinct verts v1..vk, where vi, vi+1 are adjacent
* simple cycle --> simple path that starts and ends on the same vert
* eulerian cycle --> cycle which visit every edge once

graph variants
* graph complement --> all edges not in the initial graph
* simple graph --> no multi-edge, no self loops graph
* subgraph --> graph which verts, and edges are a subset of another graph
* spanning subgraph --> subgraph that covers all the verts
* connected graph --> every vert is connected to any other vert
* connected components --> disjoint partition of a graph where each subgraph is connected
* tree --> connected graph without cycles
* rooted tree --> tree in which it is specified a root
* free tree --> tree without root
* forest --> set of free trees
* spanning tree --> spanning subgraph, connected and without cycles (free tree subgraph)
* spanning forest --> spanning subgraph, without cycles
* multiset --> set which contains the same element multiple times
* multiplicity --> number of copies of an element inside a multiset
* multigraph --> E is a multiset

mst
* cut --> disjoint partition of verts
* crossing edge --> edge where one vert is in the cut, the other is outside
* respectful cut --> cut which does not produce crossing edges
* light edge --> minimum weight crossing edge
* safe edge --> adding the edge to a mst results in another mst

## graph properties

* n+m --> size of the graph
* +++ d(v) = 2m
* m <= n^2
* G = tree --> m = n-1
* G = connected --> m >= n-1
* G = acyclic --> m <= n-1
* in any graph there is an even number of verts with odd degree

## graph representation

* L_v --> map indexed on V --> Lv[v] gives all informations on v
* L_e --> map indexed on E --> Le[e] gives all informations on e

adjacency list
* array of length n
* A[i] = list of verts adjacent to i
* space complexity --> O(n+m)

adjacency matrix
* matrix nxn indexed on the verts
* A[i,j] = 1 when the verts i,j are adjacent
* space complexity --> O(n^2)

## graph problems

* traversal --> visit all verts of a graph starting from a given vert
* determine if a graph is connected
* find all connected components
* find the minimum spanning tree
* find the shortest path between verts (less hops)
* find the cheapest path between verts
* min/max distances


## exercises

* approx min vertex cover implies approx max clique
## DFS - connected component traversal

assumptions:
* L[v].id = 0/1 (visited)
* L[e].label = null/disc/back
* all verts are unvisited
* all edges are unlabeled

output:
* all verts are marked as visited (in the connected component of v)
* all edges are labeled (in the connected component of v)
* the set of disc edges form a spanning tree

```
dfs(G, v)
    visit v

    forall null incident edges e of v
        if opposite is visited
            e = back
            return
        else
            e = disc
            dfs(G,opposite)
```

time complexity in C:
* O(+++ d(v))
* O(m) if G is a connected component

## DFS correctness

proof - all verts are visited in C:
* assume X is unvisited
* then there is a path from source to X (C is a connected component)
* then there is a first unvisited vert Y
* then there is the last visited vert Z before Y
* but DFS(G,Z) would mark Y as visited on the next call

proof - all edges are labeled in C:
* all verts are visited
* DFS labels al edges incident to a verts

proof - disc edges form a spanning tree on G:
* all verts are visited
* all visited verts are called ONCE by DFS

## DFS variants

full graph traversal
* run DFS on each vertex
* complexity --> O(n+m)

path finder
* run dfs until you reach the node, keep track of the parents

cycle detection
* mark every back edge, when you find an edge with the mark there is a loop

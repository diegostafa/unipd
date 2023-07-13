## BFS - connected component traversal

assumptions:
* L[v].id = 0/1 (visited)
* L[e].label = null/disc/cross

output:
* verts and edges are all visited and labeled --> trivial
* disc edges form a spanning BFS tree
* (proof) the path between a layer and the start is always the shortest
* (proof) verts incident in a cross edge differt at most of 1 hop from the source

```
bfs(G, v)
    visit v
    layers[0] = {v}

    for i=0, layers[i] not empty, i++
        forall v in layers[i]
            forall unlabeled edges e incident to v
                if opposite is visited
                    e = cross
                else
                    e = disc
                    layers[i+1] += opposite
```

complexity:
* O(m)

## BFS correctness

proof - you cannot reach a node in layer i with less than i hops:
* assume v to be a vert in layer i
* assume there is a shorter path to v j < i
* then v is at most at layer j
* but v cannot be in layer j because j < i

proof - cross edges must be in at most 1 layer of difference:
* assume v in layer i, u in layer i+k (k>=2)
* BFS on layer i working with v will discover u ond put it on layer i+1

## BFS variants

cycle detection
* when you find a cross edge

## exam exercises

* write an algorithm which counts the pairs of verts that are connected
* given a graph with constant degree c, prove that layer i contains less than c(c-1)^i-1 verts
* write an algorithm which returns a verte connected to at least n/2 verts

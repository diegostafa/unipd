## mst - minimum (weight) spanning tree

* problem for which we want to find the cheapest spanning tree in a weighted graph
* if weights are all different, the mst is unique

safe edge theorem
* let (S, VS) be a respectful cut to the MST
* let e be the lightest edge of (S, VS)
* then e is a safe edge for MST

algorithms:
* naive prim --> while there are crossing edges, take the lightest edge
* naive kruskal --> sort the edges and take them if they don't make a cycle
* heap prim --> optimized min edge extraction
* unionfind kruskal --> optimized cycle detection

## mst - heap prim

```
prim(G, s)
    mst = {}

    forall verts v
        cost[v] = inf

    cost[s] = 0
    heap = V sorted by cost

    while queue not empty
        min = heap.popMin

        forall edges (min, b) edajcent to min
            if w(min, b) < b.cost
                cost[b] = w(a,b)
```

## unionfind data structure

```
UnionFind
    init(A)
        forall a in A
            parent[a] = a
            size[a] = 1

    find(x)
        from x, traverse the parents and return the root

    union(x, y)
        i = find(x)
        j = find(y)

        if i == j
            return

        if i.size <=  j.size
            swap i, j

        parent[i] = j
        size[j] += size[i]
```

complexity:
* init --> O(n)
* find --> O(logn)
* union --> O(logn)

## mst - union find kruskal

```
kruskal(G)
    mst = {}
    UF.init(V)

    forall (a,b) in E.sortWeight()
        if UF.find(a) != UF.find(b)
            mst += {(a,b)}
            UF.union(a, b)

    return mst
```

complexity:
* O(mlogn)

## exercise

algorithm for the biggest spanning tree
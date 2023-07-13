## shortest paths

problem where we want to find the shortest/lightest path between verts
* shortest --> minimum edge weight

positive sssp:
* shortest path between one vert and every other vert
* only positive lengths

general sssp:
* allows for negative edges
* either return the sssp or a negative cycle

apsp:
* shortest path between every vert to every other vert
* DP bellman fors

## positive sssp - heap dijkstra

take the source, update the cost to each adjacent vert, sort by cost and do it again

```
dikstra(G, s)
    cost[s] = 0
    cost[v] = inf
    heap = verts sorted by cost

    while visited not full
        min = heap.popMin
        min.visited = true

        forall edges (a,b) incident to min where b is not visited
            cost[b] = min(cost[b], cost[a] + w)

```

correctness:
* INCOMPLETE

complexity:
* O(n * m) --> naive
* O((n+m) * logn) --> with heap to extract the min edge

## general sssp - bellman ford

```
bellman(G, s)
    forall verts v
        cost[v] = inf

    cost[s] = 0

    forall verts-1
        forall edges (a, b)
            len[b] = min(cost[b], cost[a] + w(a, b))

    forall edges (a, b)
        if cost[b] > cost[a] + w(a, b)
            return negative cycle
```

complexity:
* O(n * m)

correctness
* let len[i, v] be the length of the shortest path s-v containing at most i edges
* we want to prove that len[v] <= shortest path between s-v with at most i edges
* base case
    * cost[s] == cost[0, s]
    * cost[v] == cost[0, v]
* inductive case
    * cost[v] <= cost[k, v]


## apsp - DP bellman ford

observation:
* between s-v there is a shortest path P
* between s-(v-1) there is a shortest path P'
* then solving s-(v-1) will solve s-v

```
bellman ford DP(i, v) =
    | 0     if i == 0 and v == s
    | inf   if i == 0 and v != s
    | min(
            cost[i-1, v]
            min(cost[a-1, b] + w(a,b)) for each edge (a,b))
```

## apsp - DP floyd warshall

```
floyd warshall(G)
    enumerate V
    dist = matrix vert x vert
    set dist +inf

    forall verts a
        dist[a,a] = 0

    forall edge (a,b)
        dist[a,b] = w(a,b)

    forall verts i
        forall verts a
            forall verts b
                dist[a,i] = min(dist[a,i],dist[a,i] + dist[i,b])

    forall verts a
        if dist[a,a] < 0
            return cycle
```

complexity:
* O(n^3)
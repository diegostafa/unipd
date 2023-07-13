## flow network

props
* direct graph
* 2 verts are specified: source and sink
* each edge has a positive capacity
    * pipe size
* each edge has a positive flow value
    * what actually travels through the
    * in-f(v) --> sum of flows into v
    * out-d(f) --> sum of flows leaving v

flow constraints:
* capacity --> f(e) <= e.capacity
* conservation --> in-f(v) == out-f(v)

flow value:
* out-f(source)

max flow problem:
* find a path source/sink maximizing the flow value

## resiudal network

given a graph and a flow, we can reduce the graph:
* potential flow --> if f(e) < e.capacity --> add an edge with slack capacity
* unsending flow --> if f(e) != 0 --> add reverse edge e with the same flow

## augmenting path

path between source and sink, the bottleneck is the minimum capacity in the path

## max flow - ford fulkerson

```
ford fulkerson(G,s,t)
    set f(e) = 0
    Gf = residual(G)

    while P = augmentingPath(Gf, s, t)
        Gf = residual(G)

        forall edges e in P
            if e in E --> f(a,b) = f(b,a) + bottleneck(P)
            else      --> f(b,a) = f(b,a) - bottleneck(P)
```

complexity:
* O(m * |maxflow|) = O(n * m * max capacity)
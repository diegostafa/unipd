## terminology

* bind --> to associate something to a name
* value --> expression in its most reduced form
* callback --> function passed as parameter
* higher order function --> function which takes another function as parameter
* unit --> singleton type which represent the value of nothing
* @ --> infix operator that concat 2 lists
* :: --> infix operator that prepend an element to a list
* ; --> infix operator that takes a unit on the left and anything on the right
* lambda uplifting --> compiler optimization that uplift a lambda until it can

## beta reduction

to substitute the arguments to the body of a function and returning the new body

props:
* omega combinator --> expression that betareduce to itself

## curried form

* emulates multiple parameters
* allows partial evaluation --> better than using pairs

## list implementation

```f#
let rec map f l =
    match l with
    | [] -> []
    | x :: xs -> (f x) @ (map f xs)

let rec filter f l =
    match l with
    | [] -> []
    | x :: xs ->
        if f x then
            x @ filter f xs
        else
            filter f xs

let rec iter f l =
    match l with
    | [] -> ()
    | x :: xs -> f x ; iter f xs

let rec foldL f acc l =
    match l with
    | [] -> acc
    | x :: xs ->
        foldL f (f acc x) xs

let rec foldR f acc l =
    match l with
    | [] -> acc
    | x :: xs ->
        f (foldR f acc xs) x

let mapFoldL f l =
    foldL (fun acc e -> acc @ [f e]) [] l

let filterFoldL f l =
    foldL (fun acc e -> if f e then acc @ [e] else acc) [] l

let rec maxBy cmp l =
    match l with
    | [] -> raise (Failure "no elements")
    | [x] -> x
    | x :: xs ->
        let max = maxBy cmp xs
        if cmp x max then
            x
        else max

type 'a option = None | Some of 'a

let maxByFold cmp l =
    List.fold (fun acc e ->
        match acc with
        | None -> e
        | Some max -> if cmp max e then acc else Some e) None l
```

## tree implementation

```f#
// optional binary leaf heavy tree
type tree<'a> =
    | Leaf of 'a option
    | Node of ('a tree * 'a tree)

let rec mapTree f t =
     match t with
     | Leaf None -> Leaf None
     | Leaf (Some v) -> Leaf (f v)
     | Node (l, r) ->
        Node (mapTree f l, mapTree f r)

let rec sumTree (+) zero t =
    match t with
    | Leaf None -> zero
    | Leaf (Some v) -> v
    | Node (l, r) ->
        sumTree (+) zero l + sumTree (+) zero r

let rec filterTree f t =
    match t with
    | Leaf None -> t
    | Leaf (Some v) -> if f v then t else Leaf None
    | Node (l, r) ->
        Node (filter f l), (filter f r)

let rec foldTree f acc t =
    match t with
    | Leaf None -> acc
    | Leaf (Some v) -> f acc v
    | Node (l, r) ->
        let accL = foldTree f acc l
        foldTree f accL r

let sumTreeFold (+) zero t =
    foldTree (+) zero t

```

## n-tree implementation

```f#
type Tree<'a> =
    | Node of 'a option * List<Tree<'a>>

let rec mapTree f tree =
    match tree with
    | Node (val, children) ->
        let mapChildren = List.map (maptree f) children
        match val with
        | Some v -> Node(f v, mapChildren)
        | None -> Node(val, mapChildren)

let rec fold f acc ls =
    match ls with
    | [] -> acc
    | l :: ls ->
        foldL f (f acc l) ls

let rec foldTree f acc tree =
    match tree with
    | Node (val, children) ->
        let acc = foldTree f acc val
        List.fold (fold acc' f) acc' children

let sum (tree: Tree<int>) =
    fold 0 (+) tree

```
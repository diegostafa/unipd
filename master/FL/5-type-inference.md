## substitution

```
fi : tv -> ty
fi(t) = t
fi('a) = fi('a) or 'a if it can be substituted
fi(t1 -> t2) = fi(t1) -> fi(t2)
```

substitution composition:
* fi1°fi2 = fi1(fi2(t))
* apply fi2 to every right part of fi1

## unification

```
U : (t, t) -> fi
U(t, t) = /             // if same type
U('a, t) = ('a -> t)    // if 'a not in t
U(t, 'a) = ('a -> t)    // if 'a not in t
U(t1->t2, t3->t4) = U(t1, t3)°U(t2, t4) // substitutions composition

any other case gives an error
```

## type schemes

* type variables represent unknown types
* type schemes represent polymorphic types
* type schemes define which type variable must not be substituted (this allows polymorphism)
* the environment becomes a list of type schemes

example:
* a,b . a->b->c is a type scheme where a, b are polymorphic, while c is just unknown

## free vars

* freevars in a type are all the type variables
* freevars in a type scheme are all the type variables, minus the quantified variables

## type inference rules

only works on type schemes environments

evaluation rules:
* literal --> the type is its domain, no substitution
* variable --> if there is a scheme, instantiate it, no substitution, else error
* lambda -->
    * fake scheme the parameter in the env
    * infer the lambda body
    * after inferring the body us the substitution to try inferring the parameter
    * return param_ty -> body_ty
* application -->
    * infer the left part, propagate in the environment
    * infer the right part, propagate in the environment
    * infer the left more
    * check left is a lambda
    * return the lambda right type
* let in -->
    * infer e1
    * extend the environment with name, and the inferred type
    * infer e2
* let rec in ->
    * extend the environment with let name
    * infer e1
    * check e1 is a lambda
    * infer e2
* if then else
    * infer e1 and unify with bool
    * infer e2, infer e3, unify them
# Esercizi esame

```c++

//// funzione che identifica input output e IO

int f(ios& ref)
{
    istream i* = dynamic_cast<istream*>(&ref)
    ostream o* = dynamic_cast<ostream*>(&ref)

    if(i && o) return 0;
    if(i) return -1;
    if(o) return 1;
    return 9;
}

//// il programma deve causare un eccezione

class A 
{
    public:
    virtual ~A() {};
};

class B : public A
{}

class C : public A
{}

int main()
{
    A* pa = new A;
    B* pb = new B;
    C* pc = new C;

    *(dynamic_cast<B*>(pc));
}

//// vero o falso in base a delle condizioni sul main -- stampa pippo e pluto

template<class X>
A& fun(A& ref)
{
    return ref;
}

int main()
{
    B b;
    C c;

    fun<A>(b); // B sottotipo di A 
    B* p = new D(); // D sottotipo di B
    
    try
    {
        dynamic_cast<B&>(fun<A>(c)); // C sottotipo di A
        cout << "topoplino";
    }
    catch(bad_cast)
    {
        cout << "pippo";
    }
    if(!dynamic_cast<D*>(new B()))
        cout << "pluto";
}

//// compila o non compila (const e tipi)

C f(C& X) { return x; } // compila

C& g() const { return *this; } // non compila const C& --> C&

C h() const { return *this; } // compila

C* m() { return this; } // compila

C* n() const { return this; } // non compila

void p() {}
void q() const ( p(); ) // non compila

void p() {}
static void r(C *const  x) { x->p(); } // compila

void s(C *const x) const { *this = *x; } // non compila

static C& t() { return C(); } // 

static C *const u(C& x) { return &x: } // compila
```
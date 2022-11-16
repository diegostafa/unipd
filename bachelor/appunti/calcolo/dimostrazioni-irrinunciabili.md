## 1 - precisione macchina max errore dei floating point

ipotesi:
* x è un reale
* fl(x) è il reale macchina di x
* b è la base

tesi:
* |x - fl(x)| / |x| <= (b^1-t) / 2

dimostrazione:
* x = sign(x)(0,d0d1...dp)*b^p
* fl(x) = sign(x)(x,d0d1...dt')*b^p con dt' =
    * dt se il suo successivo < b/2
    * dt + 1 altrimenti

* stimo il numeratore:
    * |x - fl(x)| = b^p|(0,d0d1...dp) - (0,d0d1...dt')|
    * l'errore di arrotodamento è di 1/2b^t
    * quindi |x - fl(x)| <= 1/2b^t * b^p = (b^p-t)/2

* stimo il denominatore
    * 1/|x| <= 1/a
    * |x| >= a
    * cioè è sempre vero se a è il minimo reale macchina, quindi:
    * |x| >= b^-1*b^p
    * |x| >= b^p-1
    * 1/|x| <= b^1-p

* verifico le disuguaglianze    
    * (b^p-t)/2 *  b^1-p = (b^1-t) / 2 --> precisione macchina

## 2 - stabilità aritmetica macchina

moltiplicazione:
* exy = |xy - x'y'| / |xy|
* = |xy - x'y + x'y -x'y'| / |xy| --> aggiungo e sottraggo x'y
* = |y(x - x') + x'(y-y')| / |xy| --> raccolgo
* < ||y(x - x')| + |x(y - y')'|| / |xy| --> disuguaglianza triangolare
* < |y(x - xì)| / |xy| + |x'(y - y')| / |xy| --> spezzo
* < ex + (x'/x)ey --> semplifico
* è stabile in quanto il rapporto x'/x va ad 1

reciproco --> divisione:
* e1/y = |1/y - 1/y'| / |1/y|
* = |y||(y - y')/yy'|
* = |y|/|y'| * |y-y'|/|y|
* = y/y' * ey
* è stabile in quanto il rapporto y/y' va ad 1

somma algebrica:
* ex+y = |(x+y) - (x' + y')| / |x + y|
* = | x - x' + y - y'| / |x + y|
* = |x-x'|/|x+y| + |y-y'|/|x+y|
* = |x|/|x+y| * |x-x'|/|x| + |y|/|x+y| * |y-y'|/|y| --> moltiplico e divido per |x| e spezzo
* =   |x|/|x+y| * ex + |y|/|x+y| * ey --> stabile solo se x,y concordi

## 3 - convergenza bisezione

ipotesi:
* f in a,b
* f(a) e f(b) discordi
* f(c) = 0 in a,b

tesi:
* l'errore del bisezione converge a 0

dimostrazione:
* xn = (an + bn) / 2
* |c - an| e |c - bn| < bn - an = (b - a) / 2^n --> tende a 0
* |c - xn| < (bn - an) / 2 = (b - a) / 2^n+1 --> tende a 0

## 4 - bisezione con residuo pesato

stima a priori di bisezione:
* |c - xn| < (b - a) / 2^n+1 <= epsilon
* (b - a) / 2^n+1 <= epsilon
* (b - a) / epsilon <= 2^n+1
* log((b-a)/epsilon) - 1 <= n
* n >= log(b-a) + log(1/epsilon)  --> sovrastima, non funziona sempre

si introduce il residuo pesato

ipotesi:
* f(x) derivabile in [a,b]
* zn è la successione ottenuta dal teorema del valor medio

tesi:
* en = |f(xn)|/f'(zn) = |xn - c|

dimostrazione:
* applico il teorema del valor medio a c,xn
    * f(xn) - f(c) / (xn - c) = f'(zn)
    * f(xn) - f(c) = f'(zn)(xn - c) --> moltiplico per (xn - c)
    * f(xn) = f'(zn)(xn - c) --> in quanto f(c) = 0
    * f(xn)/f'(zn) = xn - c

## 5 - convergenza globale newton

ipotesi di convergenza globale:
* f(x) derivabile 2 volte in a,b
* f(a)f(b) < 0
* f''(x) sempre maggiore o minore di 0 in a,b
* f(x0) discorde a f''(x0)  
* esiste x0 : f(x0)f''(x0) > 0

tesi:
* lim xn -> c

dimostrazione:
1. dimostro che  la successione xn sta in x,b
    * f convessa --> T(x) < f(x) sempre --> se xi è in c,b, allora T(xi) cade in c,b
2. dimostro che xn decresce, cioè xn+1 < xn
    * xn+1 = xn - f(xn)/f'(xn)
    * essendo il rapporto una quantità positiva la successione è decrescente
3. dimostro che esiste lim xn = c
    * lim xn+1 = lim xn - limf(xn)/limf'(xn) =  lim xn - f(lim xn)/f'(lim xn) = c - f(c)/f'(c) --> siccome f(x) = 0 si ha che lim --> c 

## 6 - ordine convergenza newton

ipotesi:
* f(x) derivabile 2 volte
* f(c) = 0
* a < x < xn < y < b

tesi:
* e<sub>n+1</sub> <= ce<sub>n</sub>^2

dimostrazione:
* approssimo f(x) con taylor
    * f(x) = +++ f<sup>k</sup>(x0)(x - x0)<sup>k</sup>/ k! + R
* calcolo f(x) taylor al secondo grado con x=c e x0=xn
    * f(c) = f(xn) + f'(xn)(c-xn) + f''(zn)(c-xn)^2 /2
    * -f(xn)/f'(xn) = c - xn + f''(zn)/2f'(xn) (c-xn)^2 // semplifico, porto f(xn) a sx e divido tutto per f'(xn)
    * xn+1  = c +  f''(zn)/2f'(xn) (c-xn)^2
    * | xn+1 - c | = f''(zn)/2f'(xn) (c-xn)^2
    * e<sub>n+1</sub> <= ce<sub>n</sub>^2

## 7 - ordine convergenza punto fisso

ipotesi:
* f(x) derivabile p volte in [a,b]
* xn è la successione che converge a c

tesi:
1. xn converge con ordine 1 sse f'(c) sta in [0,1]
2. xn converge con ordine maggiore di 1 sse f<sup>p</sup>(c) != 0  e per ogni 1 < j < p-1  f<sup>j</sup>(c) = 0

dimostrazione 1:
* en+1 = |f'(zn)| * en
* lim en+1 / en = f'(lim zn) = f'(c)
 
## 8 - esistenza ed unicità del polinomio interpolatore

unicità:

se ci fossero 2 polinomi p,q che interpolano i nodi si avrebbe che:
* g(x) = p(x) - q(x)
* quindi g(xi) = 0 per ogni nodo
* g(x) avrebbe quindi n+1 radici
* questo va contro il teorema fondamentale dell'algebra

esistenza:

per dimostrare l'esistenza è sufficente dimostrare che da n+1 nodi diversi è sempre possibile creare il polinomio interpolatore di lagrange, per ogni nodo i definisco quindi:
* Ni(x) = (x - x0)(x - x1)...(x - xn) SENZA (x - xi)
* Ki(x) = Ni(x) / Ni(xi)
    * Ki(xk) = 1 se xk = xi --> diventa N(xi)/N(xi)
    * Ki(xk) = 0 se xk != xi --> (xk - xk) --> 0/N(xi)
* L(x) = +++ yiKi(x)
* verifico che interpola:
    *  L(xk) = +++ yiKi(xk) --> ki(xk) è sempre 0 tranne quando i = k  quindi la sommatoria è = yi

## 9 - convergenza uniforme dell'interopolatore lineare a tratti

ipotesi:
* f derivabile s+1 volte in a,b
* xi in a,b
* n+1 nodi distinti con n multiplo di s

tesi:
* esiste k > 0 tale per cui dist(f, P) < k*h^s+1

dimostrazione:
* il max errore su tutto a,b è il max dei singoli intervalli:
    * dist(f, P) = max|f(x) - P(x)| in \[a,b\] = max(max(|f(x) - P(x)|) in \[i-1,i\])
* stimiamo l'errore
    * max(|f(x) - P(x)|) in \[i-1,i\] <= max(|f^s+1(x)|)\*h^s+1/4(s+1)  in \[i-1,i\] con h = estremi dell'intervallo / s
    * uso s=1
    * max(|f(x) - P(x)|) in \[i-1,i\] <= max(|f''(x)|)\*h^2/8  in \[i-1,i\]  <= f''(x)\*h^2/8
* pongo f''(x) = M
* risulta che dist(f,P) <= M/8* h^2

## 10 - sistema di equazioni normali per l'approssimazione ai minimi quadrati

ipotesi:
* f(x) è un polinomio interpolatore sugli n nodi xi,yi
* a è un vettore lungo m con m < n
* fi(a) = +++n yi - +++m ajxi 

tesi:
* fi(a) = +++n yi - +++m ajxi sse il vettore a risolve V<sup>t</sup>Va = V<sup>t</sup>y

## 11 - stime di condizionamento di un sistema lineare

ipotesi:
* A è una matrice non singolare
* x è un vettore soluzione di Ax=b
* x' = xV<sup>t</sup>

## 12 - perchè newton ha ordine di convergenza almeno 2, e quando ha esattamente 2

dalla definizione di ordine di convergenza possiamo dire che l’ordine è almeno p = 2 per zeri semplici perché:
* en+1 ≤ ce<sub>n</sub>^2 per ogni n

ha convergenza esattamente 2 quando:
* f''(c) != 0

## 13 - instabilità sottrazione stima ed esempio

la sottrazione è più instabile quando i 2 numeri sono relativamente vicini, cioè quando:
* x,y > max(1/ex, 1/ey)

esempio:
* f(x) = ((1+x) - 1)/x  con x =  10^-15 il risultato è 1,111... 11% di errore


**domande aperte**

+ perchè moltiplicazione, divisione, addizione sono stabili
+ perchè la sottrazione è instabile, fare un esempio
+ perchè il residuo non pesato non è una buona stima
+ perche newton converge con ordine 2, quando ha esattamente 2
+ dimostra convergenza newton se strettamente convesso/concavo
+ perchè l'interpolatore di grado n è unico, si faccia un esempio con grado < n
+ discutere esistenza del polinomio interpolatore
- stima errore sistema lineare con vettore termine noto affetto da errori
- perchè l'interpolazione a tratti converge con O(h^2)
- derivazione numerica con rapporto incrementale simmetrico
- perchè l'errore sulla formuala dei trapezi e O(h^2)
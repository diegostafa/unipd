**condizionamento di matrici**

consiste nel studiare l'errore di:
* Ax = b

se A è invertibile la soluzione è unica

scelta una norma, l'errore assoluto è:
* ||dx|| = ||x - x0||

si vuole quindi studiare l'errore:
* A(x + dx) = b + db

da cui si ricava che l'erroe commesso è:
* ||A'||\*||A||\*||db||/||b||

l'indice di condizionamento della matrice è:
*  k(A) = ||A'||*||A||

e vale la seguente disuguaglianza
* k(A) >= |autovalori di mod maggiore| / |autovalori di mod minore

il sistema si dice mal condizionato se k(A) >> 1
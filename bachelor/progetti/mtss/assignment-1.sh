#! /bin/bash


# ---- REPO PROJECT ISSUE E MILESTONE ----

# stafa - init
mkdir "MTSS-first-assignment"
cd "MTSS-first-assignment"
code .
git flow init
git remote add origin "https://github.com/diegostafa/MTSS-first-assignment.git"
git push -u origin master
git push -u origin develop

# ciano - clone
git clone "https://github.com/diegostafa/MTSS-first-assignment.git"
cd "MTSS-first-assignment"
code .
git flow init

# stafa - attività 1
git flow feature start creazione-inventario
echo "1226285" >> inventario.md
echo "1224452" >> inventario.md
git add .
git commit -m "creato inventario.md, close #1"
git push -u origin feature/creazione-inventario
git flow feature finish -k creazione-inventario
git push

# ciano
git pull

# stafa - attività 2
git flow feature start processori
echo "1226285" >> processori.md
echo "1224452" >> processori.md
echo "processori.md" >> inventario.md
git add .
git commit -m "creato processori.md, close #2"
git push -u origin feature/processori
git flow feature finish -k processori
git push

# ciano - attività 3
git flow feature start schede-madri
echo "1226285" >> schede_madri.md
echo "1224452" >> schede_madri.md
echo "schede_madri.md" >> inventario.md
git add .
git commit -m "creato schede_madri.md, close #3"
git push -u origin feature/schede-madri
git flow feature finish -k schede-madri
git push
# !!! conflitto !!!
git pull
git add .
git commit -m "risolto conflitto inventario"
git push

# stafa - release prima versione
git pull
git flow release start prima-versione
git push -u origin release/prima-versione
echo "Elettronica Padovana" >> inventario.md
git add .
git commit -m "aggiunto nome del negozio all'inventario"
git flow release finish prima-versione
git push origin master
git push origin develop
git push origin --tags

# ---- ISSUE E MILESTONE -----


# ciano - attività 4
git flow feature start sezione-componenti
mkdir componenti
mv processori.md componenti
mv schede_madri.md componenti
# !!! aggiornare inventario !!!
git add .
git commit -m "close #4"
git push -u origin feature/sezione-componenti
git flow feature finish -k sezione-componenti
git push
# !!! conflitto !!!
git pull
git add .
git commit -m "risolto conflitto inventario"
git push

# stafa - attività 5
git pull
git flow feature start periferiche
mkdir periferiche
touch periferiche/file.md
# !!! aggiornare inventario !!!
git add .
git commit -m "aggiunta sezione periferiche, close #5"
git push -u origin feature/periferiche
git flow feature finish -k periferiche
git push

# ciano - attività 6
git pull
git flow feature start tastiere
cd periferiche
echo "1226285" >> tastiere.md
echo "1224452" >> tastiere.md
git add .
git commit -m "creato tastiere.md, close #6"
git push -u origin feature/tastiere
git flow feature finish -k tastiere
git push

# stafa - attività 7
git pull
git flow feature start mouse
cd periferiche
echo "1226285" >> mouse.md
echo "1224452" >> mouse.md
git add .
git commit -m "creato mouse.md, close #7"
git push -u origin feature/mouse
git flow feature finish -k mouse
git push

# ciano - release seconda versione
git pull
git flow release start seconda-versione
git push -u origin release/seconda-versione

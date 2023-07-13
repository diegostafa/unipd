#---------------------------------------#
#---------------INSIEMI-----------------#
#---------------------------------------#

# insieme delle rarità
set rarita;

# insieme dei mazzi
set mazzo;

# insieme dei livelli
set livello;

#---------------------------------------#
#---------------PARAMETRI---------------#
#---------------------------------------#

# --- PARAMETRI DEL TORNEO


# numero di carte minime per mazzo 
param min_carte;

# numero di carte massime per mazzo
param max_carte;

# numero di mostri minimi per mazzo
param min_mostri;

# numero di magie minime per mazzo
param min_magie;

# somma dei livelli totali minimi in almeno un mazzo
param min_lv_tot;


# --- PARAMETRI CREATIVI

# numero minimo di mostri di livello 1
param min_mostri_lv_1;

# numero minimo di mostri di livello 5
param min_mostri_lv_5;

# numero minimo di carte ultra rare che il secondo 
# o terzo mazzo devono avere
param max_carte_ultra_secondo_terzo;

# --- PARAMETRI DI RARITÀ


# valore di una carte in base alla rarità
param valore_rarita{rarita};


# --- PARAMETRI DI PREZZO


# costo di un mostro, dati rarità e livello
param costo_mostro{rarita, livello};

# costo di una magia, data la rarità
param costo_magia{rarita};

# costo di una trappola, data la rarità
param costo_trappola{rarita};

# soldi disponibili per l'acquisto delle carte
param soldi_disponibili;


# --- COSTANTI MINIME DI ATTIVAZIONE

param SOMMA_LIVELLI_MASSIMA;
param NUM_MAZZI;
param NUM_LIVELLI;
param NUM_RARITA;

#---------------------------------------#
#--------------VARIABILI----------------#
#---------------------------------------#

# numero di carte mostro per: rarità, livello e mazzo
var carte_mostro{rarita, livello, mazzo} >= 0 integer;

# numero di carte magia per: rarità e mazzo
var carte_magia{rarita, mazzo} >= 0 integer;

# numero di carte trappola per: rarità e mazzo
var carte_trappola{rarita, mazzo} >= 0 integer;

#---------------------------------------#
#-----------FUNZIONE OBIETTIVO----------#
#---------------------------------------#

# la somma delle rarità in tutti i mazzi deve essere massima
maximize rarita_mazzi:
	(sum{m in mazzo, r in rarita, l in livello}
		valore_rarita[r]*carte_mostro[r, l, m])+
	(sum{m in mazzo, r in rarita}
		valore_rarita[r]*carte_magia[r, m]) +
	(sum{m in mazzo, r in rarita}
		valore_rarita[r]*carte_trappola[r, m]);

#---------------------------------------#
#---------------VINCOLI-------- ---------#
#---------------------------------------#

# --- VINCOLI DI BUDGET

# V0: la spesa per le carte non deve superare i soldi disponibili
s.t. spesa_massima:
	(sum{m in mazzo, r in rarita, l in livello}
		costo_mostro[r,l]*carte_mostro[r, l, m])/10 +
	(sum{m in mazzo, r in rarita}
		costo_magia[r]*carte_magia[r, m])/10 +
	(sum{m in mazzo, r in rarita}
		costo_trappola[r]*carte_trappola[r, m])/10
	<=
	soldi_disponibili;


# --- VINCOLI DI TORNEO

# V1 : ogni mazzo deve avere un numero minimo di carte
s.t. carte_minime{m in mazzo}:
	(sum{l in livello, r in rarita} carte_mostro[r, l, m]) +
	(sum{r in rarita} carte_magia[r, m]) +
	(sum{r in rarita} carte_trappola[r, m])	
	>=
	min_carte;

# V2 : ogni mazzo deve avere un numero massimo di carte
s.t. carte_massime{m in mazzo}:
	(sum{l in livello, r in rarita} carte_mostro[r, l, m]) +
	(sum{r in rarita} carte_magia[r, m]) +
	(sum{r in rarita} carte_trappola[r, m])	
	<=
	max_carte;

# V3 : ogni mazzo deve avere un numero minimo di mostri
s.t. mostri_minimi{m in mazzo}:
	(sum{l in livello, r in rarita} carte_mostro[r, l, m])
	>=
	min_mostri;
	
# V4 : ogni mazzo deve avere un numero minimo di magie
s.t. magie_minime{m in mazzo}:
	(sum{r in rarita} carte_magia[r, m])
	>=
	min_magie;
	
# --- VINCOLI CREATIVI

# [LOGICO] V5 : un solo mazzo può avere il massimo numero di carte

# 1 se il mazzo specificato ha meno di 60 carte, 0 altrimenti
var ha_60_carte{mazzo} binary;

s.t. attiva_ha_60_carte{m in mazzo}:
	(sum{l in livello, r in rarita} carte_mostro[r, l, m]) +
	(sum{r in rarita} carte_magia[r, m]) +
	(sum{r in rarita} carte_trappola[r, m])
	<=
	max_carte - 1 +
	max_carte*ha_60_carte[m];
	
s.t. attiva_ha_60_carte_2{m in mazzo}:
	(sum{l in livello, r in rarita} carte_mostro[r, l, m]) +
	(sum{r in rarita} carte_magia[r, m]) +
	(sum{r in rarita} carte_trappola[r, m])
	>=
	max_carte - 1 -
	max_carte*(1 - ha_60_carte[m]);


# soddisfa il vincolo
s.t. massimo_numero_mazzi_con_60_carte:
	(sum{m in mazzo} ha_60_carte[m])
	<=
	1;


# [LOGICO] V6 : il livello totale dei mostri in almeno un mazzo
#				deve essere almeno 30

# 1 se il mazzo specificato ha la somma dei livelli totale minore di 30, 0 altrimenti
var lv_tot_almeno_30{mazzo} binary; 

s.t. attiva_lv_tot_almeno_30{m in mazzo}:
	(sum{l in livello, r in rarita} l*carte_mostro[r, l, m])
	<=
	min_lv_tot - 1 +
	max_carte*lv_tot_almeno_30[m];
	
s.t. attiva_lv_tot_almeno_30_2{m in mazzo}:
	(sum{l in livello, r in rarita} l*carte_mostro[r, l, m])
	>=
	min_lv_tot - 1 -
	max_carte*(1 - lv_tot_almeno_30[m]);

# soddisfa il vincolo
s.t. massimo_numero_mazzi_con_lv_totale_30:
	(sum{m in mazzo} lv_tot_almeno_30[m])
	<=
	1;
	
	
# [LOGICO] V7 : ogni mazzo deve contenere almeno una carta per ogni rarita

# 1 se il mazzo specificato ha la rarità specificata, 0 altrimenti
var ha_rarita{rarita, mazzo} binary; 

# 1 se il mazzo  specificato non ha tutte le rarita, 0 altrimenti
var non_ha_tutte_rarita{mazzo} binary;

s.t. attiva_ha_rarita{r in rarita, m in mazzo}:
	(sum{l in livello} carte_mostro[r, l, m]) +
	carte_magia[r, m] +
	carte_trappola[r, m]
	<=
	max_carte*ha_rarita[r, m];

s.t. attiva_ha_rarita_2{r in rarita, m in mazzo}:
	(sum{l in livello} carte_mostro[r, l, m]) +
	carte_magia[r, m] +
	carte_trappola[r, m]
	>=
	1 - max_carte*(1 - ha_rarita[r, m]);
	

s.t. attiva_non_ha_tutte_rarita{m in mazzo}:
	(sum{r in rarita} ha_rarita[r, m])
	>=
	NUM_RARITA - NUM_MAZZI*NUM_RARITA*non_ha_tutte_rarita[m];

# soddisfa il vincolo
s.t. ogni_mazzo_con_tutte_rarita:
	(sum{m in mazzo} non_ha_tutte_rarita[m])
	=
	0;
	
	
# [LOGICO] V9 : almeno un mazzo deve contenere un mostro per ogni livello

# 1 se il mazzo specificato ha un mostro per il livello specificato, 0 altrimenti
var ha_lv{livello, mazzo} binary;

# 1 se il mazzo specificato non ha un mostro per ogni livello, 0 altrimenti
var non_ha_tutti_lv{mazzo} binary;

s.t. attiva_ha_lv{l in livello, m in mazzo}:
	(sum{r in rarita} carte_mostro[r, l, m])
	<=
	max_carte*ha_lv[l, m]; # num lv 
	
s.t. attiva_ha_lv_2{l in livello, m in mazzo}:
	(sum{r in rarita} carte_mostro[r, l, m])
	>=
	1 - max_carte*(1 - ha_lv[l, m]);
	
s.t. attiva_non_ha_tutti_lv{m in mazzo}:
	(sum{l in livello} ha_lv[l, m])
	>=
	NUM_LIVELLI - NUM_MAZZI*NUM_LIVELLI*non_ha_tutti_lv[m];

# soddisfa il vincolo
s.t. almeno_un_mazzo_con_tutti_lv:
	(sum{m in mazzo} non_ha_tutti_lv[m])
	<=
	NUM_MAZZI - 1;


# [LOGICO] V10 : il secondo oppure il terzo mazzo
# devono avere al massimo 3 carte ultra rare

# 1 se il secondo mazzo ha più di 3 carte ultra rare, 0 altrimenti
var ha_3_ultra_secondo_mazzo binary; 

# 1 se il terzo mazzo ha più di 3 carte ultra rare, 0 altrimenti
var ha_3_ultra_terzo_mazzo binary;

s.t. attiva_ha_3_ultra_secondo_mazzo:
	(sum{l in livello} carte_mostro["ultra", l, "secondo"]) +
	carte_magia["ultra", "secondo"] +
	carte_trappola["ultra", "secondo"]
	<=
	max_carte_ultra_secondo_terzo +
	max_carte*ha_3_ultra_secondo_mazzo;
	
s.t. attiva_ha_3_ultra_secondo_mazzo_2:
	(sum{l in livello} carte_mostro["ultra", l, "secondo"]) +
	carte_magia["ultra", "secondo"] +
	carte_trappola["ultra", "secondo"]
	>=
	max_carte_ultra_secondo_terzo -
	max_carte*(1 - ha_3_ultra_secondo_mazzo);

s.t. attiva_ha_3_ultra_terzo_mazzo:
	(sum{l in livello} carte_mostro["ultra", l, "secondo"]) +
	carte_magia["ultra", "secondo"] +
	carte_trappola["ultra", "secondo"]
	<=
	max_carte_ultra_secondo_terzo +
	max_carte*ha_3_ultra_terzo_mazzo;
	
s.t. attiva_ha_3_ultra_terzo_mazzo_2:
	(sum{l in livello} carte_mostro["ultra", l, "terzo"]) +
	carte_magia["ultra", "terzo"] +
	carte_trappola["ultra", "terzo"]
	>=
	max_carte_ultra_secondo_terzo -
	max_carte*(1 - ha_3_ultra_terzo_mazzo);

# soddisfa il vincolo
s.t. 3_ultra_secondo_terzo:
	ha_3_ultra_secondo_mazzo +
	ha_3_ultra_terzo_mazzo
	<=
	1;


# V11 :	il primo mazzo contiene tante super rare quante
#		il minimo di super rare tra il secondo e terzo mazzo

# contiene il minimo tra:
# 	- numero di carte super rare nel secondo mazzo
# 	- numero di carte super rare nel terzo mazzo
var min_super_secondo_terzo >= 0 integer;

s.t. min_super_secondo_mazzo:
	min_super_secondo_terzo
	<=
	(sum{l in livello} carte_mostro["super", l, "secondo"]) +
	carte_magia["super", "secondo"] +
	carte_trappola["super", "secondo"];
	
s.t. min_super_terzo_mazzo:
	min_super_secondo_terzo
	<=
	(sum{l in livello} carte_mostro["super", l, "terzo"]) +
	carte_magia["super", "terzo"] +
	carte_trappola["super", "terzo"];
	
# soddisfa il vincolo
s.t. comuni_primo_mazzo_uguale_minimo:
	(sum{l in livello} carte_mostro["super", l, "primo"]) +
	carte_magia["super", "primo"] +
	carte_trappola["super", "primo"]
	=
	min_super_secondo_terzo;
	
	
# V12 : il numero di carte comuni nel il primo
#		e terzo mazzo deve essere uguale

s.t. uguaglianza_comuni:
	(sum{l in livello} carte_mostro["comune", l, "primo"]) +
	carte_magia["comune", "primo"] +
	carte_trappola["comune", "primo"]	
	=
	(sum{l in livello} carte_mostro["comune", l, "terzo"]) +
	carte_magia["comune", "terzo"] +
	carte_trappola["comune", "terzo"];
	
	
# V13 :	il numero di carte ultra rare nel terzo mazzo deve essere
#		uguale alla differenza di carte super rare nel secondo mazzo
# 		e di comuni nel primo mazzo

# contiene il valore assoluto della differenza tra:
#	- numero di carte super rare nel secondo mazzo
# 	- numero di carte comuni nel primo mazzo
var differenza_assoluta_super_comuni >= 0 integer;

s.t. diff_positiva:
	differenza_assoluta_super_comuni
	>=
	(sum{l in livello} carte_mostro["super", l, "primo"]) +
	carte_magia["super", "primo"] +
	carte_trappola["super", "primo"]
	-
	(sum{l in livello} carte_mostro["comune", l, "primo"]) +
	carte_magia["comune", "primo"] +
	carte_trappola["comune", "primo"];

s.t. diff_negativa:
	differenza_assoluta_super_comuni
	>=
	-(
		(sum{l in livello} carte_mostro["super", l, "primo"]) +
		carte_magia["super", "primo"] +
		carte_trappola["super", "primo"]
		-
		(sum{l in livello} carte_mostro["comune", l, "primo"]) +
		carte_magia["comune", "primo"] +
		carte_trappola["comune", "primo"]
	);

# soddisfa il vincolo
s.t. uguaglianza_ultra:
	(sum{l in livello} carte_mostro["ultra", l, "terzo"]) +
	carte_magia["ultra", "terzo"] +
	carte_trappola["ultra", "terzo"]
	=
	differenza_assoluta_super_comuni;


# [LOGICO] V14 :	se almeno un mazzo ha almeno 10 mostri di livello 1
# 					allora almeno un mazzo deve avere almeno 5 mostri
# 					di livello 5

# 1 se il mazzo specificato ha almeno 10 mostri di livello 1, 0 altrimenti
var ha_10_lv_1{mazzo} binary;

# 1 se il mazzo specificato ha almeno 5 mostri di livello 5, 0 altrimenti
var ha_5_lv_5{mazzo} binary;

# 1 se almeno un mazzo ha 10 mostri di livello 1, 0 altrimenti
var ce_un_mazzo_con_10_lv_1 binary;

s.t. attiva_ha_10_lv_1{m in mazzo}:
	(sum{r in rarita} carte_mostro[r, 1, m])
	<=
	min_mostri_lv_1 - 1 +
	max_carte*ha_10_lv_1[m];
	
s.t. attiva_ha_10_lv_1_2{m in mazzo}:
	(sum{r in rarita} carte_mostro[r, 1, m])
	>=
	min_mostri_lv_1 - 1 -
	max_carte*(1 - ha_10_lv_1[m]);
	
s.t. attiva_ha_5_lv_5{m in mazzo}:
	(sum{r in rarita} carte_mostro[r, 5, m])
	<=
	min_mostri_lv_5 - 1 +
	max_carte*ha_5_lv_5[m];
	
s.t. attiva_ha_5_lv_5_2{m in mazzo}:
	(sum{r in rarita} carte_mostro[r, 5, m])
	>=
	min_mostri_lv_5 - 1 -
	max_carte*(1 - ha_5_lv_5[m]);

s.t. attiva_ce_un_mazzo_con_10_lv_1:
	(sum{m in mazzo} ha_10_lv_1[m])
	<=
	NUM_MAZZI*ce_un_mazzo_con_10_lv_1;
	
s.t. attiva_ce_un_mazzo_con_10_lv_1_2:
	(sum{m in mazzo} ha_10_lv_1[m])
	>=
	- NUM_MAZZI*(1 - ce_un_mazzo_con_10_lv_1);
	
# soddisfa il vincolo
# spiegazione:
# - se 0 allora ci possono anche non essere 5 mostri di livello 5 nei mazzi
# - se 1 allora ci deve essere almeno un mazzo con 5 mostri di livello 5
s.t. se_10_allora_5:
	(sum{m in mazzo} ha_5_lv_5[m])
	>=
	ce_un_mazzo_con_10_lv_1;
#include "item.h"

typedef struct node *list;

/* FUNZIONE UTILE A CREARE UNA NUOVA LISTA VUOTA */
list newList(void);

/* FUNZIONE CHE CONTROLLA SE LA LISTA È VUOTA */
int emptyList(list l);

/* FUNZIONE UTILE ALL'INSERIMENTO DI NUOVI ELEMENTI NELLA LISTA */
list consList(item val, list l);

/* FUNZIONE UTILE ALLO SCORRIMENTO DELLA LISTA */
list tailList(list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL PRIMO ELEMENTO DELLA LISTA */
item getFirst (list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA GRANDEZZA DELLA LISTA IN MODO ITERATIVO */
int sizeList (list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA POSIZIONE DI UN ELEMENTO CERCATO NELLA LISTA */
int posItem (list l, item val);

/* FUNZIONE UTILE ALL'OTTENIMENTO DI UN ELEMENTO CORRISPONDENTE AD UNA POSIZIONE CERCATA NELLA LISTA */
item getItem (list l, int pos);

/* FUNZIONE UTILE A INVERTIRE LA LISTA */
list reverseList (list l);

/* FUNZIONE UTILE ALLA STAMPA DEGLI ELEMENTI DELLA LISTA */
void outputList (list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA GRANDEZZA DELLA LISTA IN MODO RICORSIVO */
int contaRicorsivo(list l);
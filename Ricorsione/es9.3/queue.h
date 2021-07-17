#include "item.h" 

/* STRUTTURA CHE IDENTIFICA LA CODA */  
typedef struct Queue *queue;

/* FUNZIONE UTILE A CREARE UNA NUOVA CODA */
queue newQueue(void);

/* FUNZIONE UTILE A CONTROLLARE CHE LA CODA SIA VUOTA */
int emptyQueue(queue q);

/* FUNZIONE UTILE A INSERIRE ITEM NELLA CODA */
int enqueue(item val, queue q);

/* FUNZIONE UTILE A PRELEVARE E RIMUOVERE L'ITEM IN TESTA ALLA CODA */
item dequeue(queue q);

/* FUNZIONE UTILE ALLA STAMPA DELLA CODA */
void outputQueue(queue q);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL NUMERO DI ELEMENTI PRESENTI IN LISTA */
int getSize(queue q);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL VALORE DELL'ITEM PRESENTE IN TESTA ALLA LISTA SENZA PERO' RIMUOVERLO */
item getItem(queue q, int n);

/* FUNZIONE UTILE A UNIRE DUE CODE */
queue concatena(queue q1, queue q2);

/* FUNZIONE UTILE AL CALCOLO DELLA SPEZZATA IN MODO ITERATIVO */
float spezzataIterativa(queue q);

/* FUNZIONE UTILE AL CALCOLO DELLA SPEZZATA IN MODO RICORSIVO */
float spezzataRicorsiva(queue q, int cont, float somma);
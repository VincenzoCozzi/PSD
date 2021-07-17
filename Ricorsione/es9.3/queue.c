#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "queue.h"

/* STRUTTURA CHE IDENTIFICA UN NODO */   
struct node {
     item value;
     struct node *next;
};

/* STRUTTURA CHE IDENTIFICA LA CODA */   
struct Queue {
     struct node *head,*tail;
     int numel;
};

/* FUNZIONE UTILE A CREARE UNA NUOVA CODA */
queue newQueue(void){
     struct Queue *q; // Dichiarazione di un puntatore alla struttura coda
     q = malloc (sizeof(struct Queue)); // Allocazione dinamica della memoria alla coda
     if (q == NULL){ // Se il puntatore risulta nullo, viene restituito il valore null alla funzione chiamante
          return NULL;
     } 
     q->numel = 0; // Inizializzazione del valore numel, atto a contenere il numero di elementi presenti in coda
     q->head = NULL; // Inizializzazione del nodo head
     q->tail = NULL; // Inizializzazione del nodo tail
     return q; // Ritorno della coda alla funzione chiamante
} 

/* FUNZIONE UTILE A CONTROLLARE CHE LA CODA SIA VUOTA */
int emptyQueue(queue q){
     if (q==NULL){ // Se la coda risulta nulla, viene restituito il valore -1 alla funziona chiamante
          return -1;
     }
     return q->numel == 0; // Ritorno del risultato del confronto tra il numero di elementi presenti nella coda e 0
}

/* FUNZIONE UTILE A INSERIRE ITEM NELLA CODA */
int enqueue(item val, queue q){
     if (q==NULL){ // Se la coda risulta nulla, viene restituito il valore -1 alla funziona chiamante
          return -1;
     }
     struct node *nuovo; // Dichiarazione di un nodo 
     nuovo = malloc (sizeof(struct node)); // Allocazione dinamica della memoria al nodo
     if (nuovo == NULL){ // Se il nodo risulta nullo, viene restituito il valore 0 alla funzione chiamante
          return 0;
     }
     nuovo->value = val; // Assegnamento dell'item passato dalla funzione chiamante all'item del nodo
     nuovo->next= NULL; // Assegnamento del nodo next come nullo
     if(q->head==NULL) { // Controllo della presenza di elementi nella coda
          q->head = nuovo; // Se la coda risulta vuota, il nuovo nodo verrà messo in testa alla coda
     } else {
          q->tail->next= nuovo; // Se la coda non risulta vuota, il nuovo nodo verrà messo in coda alla coda
     }
     q->tail = nuovo; // Assegnamento del nuovo nodo a tail
     (q->numel)++; // Incremento del numero di elementi presenti nella coda
     return 1; // Ritorno del valore 1 in caso sia andato tutto bene
}

/* FUNZIONE UTILE A PRELEVARE E RIMUOVERE L'ITEM IN TESTA ALLA CODA */
item dequeue(queue q){
     if (q==NULL){ // Se la coda risulta nulla, viene restituito NULLITEM
         return NULLITEM; 
     } 
     if (q->numel == 0){ // Se la coda risulta vuota, viene restituito NULLITEM
          return NULLITEM;
     }    
     item val = q->head->value; // Dichiarazione e inizializzazione dell'item da resistuire
     struct node *tmp = q->head; // Nodo da eliminare
     q->head = q->head->next; // Scorrimento dell'head di una posizione
     free(tmp); // Eliminazione del nodo
     if(q->head==NULL){ // Se ora la coda risulta vuota, head e tail vengono impostati su NULL
          q->tail=NULL; 
     } 
     (q->numel)--; // Decremento del numero di elementi presenti in coda
     return val; // Ritorno alla funzione chiamante dell'item appena prelevato
}

/* FUNZIONE UTILE ALLA STAMPA DELLA CODA */
void outputQueue(queue q){
     struct node *tmp=q->head; // Dichiarazione di un nodo temporaneo utile a scorrere la coda
     printf("\n");
     /* Ciclo utile allo scorrimento della coda fino alla fine */
     while(tmp!=NULL){
          output_item(tmp->value); // Stampa dell'item presente nel nodo attuale
          printf("\n");
          tmp=tmp->next; // Scorrimento della coda, passando al nodo successivo
     }
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL NUMERO DI ELEMENTI PRESENTI IN LISTA */
int getSize(queue q){
     return q->numel; // Ritorno del numero di elementi alla funzione chiamante
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL VALORE DELL'ITEM PRESENTE IN TESTA ALLA LISTA SENZA PERO' RIMUOVERLO */
item getItem(queue q, int n){
     struct node *tmp = q->head; // Dichiarazione di un nodo assegnandogli il nodo presente in testa alla coda
     /* Ciclo che si ripete un numero n di volte, utile a scorrere di n posizioni la coda */
     for(int i=0; i<n; i++){
          tmp=tmp->next; // Scorrimento della coda
     }
     return tmp->value; // Ritorno dell'item alla funzione chiamante
}

/* FUNZIONE UTILE A UNIRE DUE CODE */
queue concatena(queue q1, queue q2){
     queue coda=newQueue(); // Dichiarazione e inizializzazione di una nuova coda
     coda->numel=q1->numel+q2->numel; // Impostazione del numero di elementi della nuova coda come la somma delle due code da unire
     coda=q1; // Assegnamento della prima coda alla seconda
     coda->tail->next=q2->head; // Assegnamento dell'head della seconda coda al nodo successivo al tail della prima
     coda->tail=q2->head; // Assegnamento del tail della prima coda come l'head della seconda
     return coda; // Ritorno della coda
}

/* FUNZIONE UTILE AL CALCOLO DELLA SPEZZATA IN MODO ITERATIVO */
float spezzataIterativa(queue q){

     item tmp1, tmp2;
     float somma=0;

     /* Ciclo utile allo scorrimento di tutta la coda */
     for(int i=0; i<getSize(q)-1; i++){
          tmp1=getItem(q,i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
          tmp2=getItem(q,i+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
          somma+=distanza(tmp1, tmp2); // Incremento del valore somma per la distanza tra i due punti appena prelevati
     }
}

/* FUNZIONE UTILE AL CALCOLO DELLA SPEZZATA IN MODO RICORSIVO */
float spezzataRicorsiva(queue q, int cont, float somma){
     item tmp1, tmp2;

     /* Ciclo utile allo scorrimento di tutta la coda */
     if(cont<getSize(q)-1){
          tmp1=getItem(q,cont); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
          tmp2=getItem(q,cont+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
          cont++;
          return somma+=distanza(tmp1, tmp2)+spezzataRicorsiva(q, cont, somma); // Incremento del valore somma per la distanza tra i due punti appena prelevati
     }
     
}



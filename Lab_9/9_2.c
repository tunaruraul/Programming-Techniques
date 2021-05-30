/*Aplicația 9.2: Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele
inversate. Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm){
    elem *e;
    e = (elem*)malloc(sizeof(elem));
    if(e == NULL){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    e->n = n;
    e->urm = urm;
    return e;
}

elem *inversareLista(elem *e){
    elem *pre = NULL;
    elem *p = e;
    while(p != NULL){
        elem *urmator = p->urm;
        p->urm = pre;
        pre = p;
        p = urmator;
    }
    return pre;
}

void afisare(elem *lista){
    for(;lista;lista = lista->urm){
        printf("%d ", lista->n);
        }
    putchar('\n');
}

void eliberare(elem *lista){
    elem *p;
    while(lista){
        p = lista->urm;
        free(lista);
        lista = p;
        }
}

int main(){
    elem *lista1 = nou(108, nou(-1, nou(49, NULL)));
    afisare(inversareLista(lista1));
    eliberare(inversareLista(lista1));

    return 0;
}

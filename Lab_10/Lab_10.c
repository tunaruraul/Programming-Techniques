#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod{
    int val;
    struct nod *pred;
    struct nod *urm;
}nod;


typedef struct{
	nod *prim;
	nod *ultim;
}list;


nod *nod_nou(int val){
	nod *nou;
	nou = (nod*)malloc(sizeof(nod));
	if(!nou)
    {
		printf("EROARE!\n");
		free(nou);
		exit(EXIT_FAILURE);
	}
	nou->val=val;
	return nou;
}


void eliberare(list *list){
    nod *n=list->prim, *aux;
    while(n)
    {
        aux=n;
        n=n->urm;
        free(aux);
    }
}


void inserareIn(list *list, int val){
    nod *nou=(nod *)malloc(sizeof(nod));
    if (!nou){
        eliberare(list);
        printf("EROARE");
        free(nou);
		exit(EXIT_FAILURE);
    }
    nou->val=val;
    nou->urm=NULL;
    nou->pred=NULL;
    if (list->prim) {
        nou->urm=list->prim;
        list->prim->pred=nou;
        list->prim=nou;
    }
    else{
        list->prim=nou;
        list->ultim=nou;
    }
}


void inserareSf(list *list, int val){
    nod *nou=(nod *)malloc(sizeof(nod));
    if (!nou){
        eliberare(list);
        printf("EORARE");
        free(nou);
		exit(EXIT_FAILURE);
    }
    nou->val=val;
    nou->urm=NULL;
    nou->pred=NULL;
    if (list->ultim){
        nou->pred=list->ultim;
        list->ultim->urm=nou;
        list->ultim=nou;
    }
    else{
        list->prim=nou;
        list->ultim=nou;
    }
}


void afis(list *list){
    nod *copie;
    for(copie=list->prim;copie;copie=copie->urm)
        printf("%d ",copie->val);
    printf("\n");
}


void sterg(list* list,int v){
    nod* crt;
    for(crt=list->prim;crt;crt=crt->urm)
        if(crt->val==v)
        {
            if(crt->pred == NULL){
                crt = crt->urm;
                crt->pred=NULL;
                list->prim=crt;
             }
            else
                if(crt->urm == NULL){
                    list->ultim=crt->pred;
                    crt->pred->urm=NULL;
                }
                else{
                    crt->pred->urm=crt->urm;
                    crt->urm->pred=crt->pred;
                }
                free(crt);
        }
}

int main(){
    list list;
    list.prim = NULL;
    list.ultim = NULL;
	inserareIn(&list,2);
	inserareIn(&list,1);
	inserareSf(&list,3);
	afis(&list);
	sterg(&list,2);
	afis(&list);
	return 0;
}

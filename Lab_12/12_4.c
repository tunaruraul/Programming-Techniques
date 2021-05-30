/*Aplicația 12.4: La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int).
Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor,
astfel încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și
ei în grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe,
pentru valori citite dintr-un fișier.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char nume[16];
    int valoare;
} Jucator;

int compare(const void *_j1, const void *_j2){
    Jucator *j1 = (Jucator *)_j1;
    Jucator *j2 = (Jucator *)_j2;
    return j2->valoare - j1->valoare;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (n % m != 0){
        printf("n nu este divizibil cu m");
        return 0;
    }

    Jucator jucatori[n];
    for (int i = 0; i < n; i++)
        scanf("%s%d", jucatori[i].nume, &(jucatori[i].valoare));

    qsort(jucatori, n, sizeof(Jucator), compare);

    qsort(jucatori, n, sizeof(Jucator), compare);

    for (int i = 0; i < m; i++){
        printf("echipa %d:\n", i + 1);
        for (int j = i; j < n; j += m)
            printf("Nume:%s, valoare:%d\n", jucatori[j].nume, jucatori[j].valoare);
    }
}
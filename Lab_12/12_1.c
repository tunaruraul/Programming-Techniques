/*Aplicația 12.1: Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan. Fiecare punct reprezintă
poziția unde va trebui dată o gaură într-o placă. Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de
dat găuri, astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} Punct;

int compare(const void *_p1, const void *_p2){
    Punct *p1 = (Punct *)_p1;
    Punct *p2 = (Punct *)_p2;
    float d1 = sqrt(p1->x * p1->x + p1->y * p1->y), d2 = sqrt(p2->x * p2->x + p2->y * p2->y);
    return d1 - d2;
}

int main(){
    int n;
    scanf("%d", &n);

    Punct puncte[n];
    for (int i = 0; i < n; i++)
        scanf("%f%f", &(puncte[i].x), &(puncte[i].y));

    qsort(puncte, n, sizeof(Punct), compare);
    for (int i = 0; i < n; i++)
        printf("%g %g\n", puncte[i].x, puncte[i].y);
}
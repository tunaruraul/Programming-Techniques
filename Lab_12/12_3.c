/*Aplicația 12.3: Definim reducerea unei matrici cu elemente întregi ca fiind valoarea calculată astfel: dacă
matricea nu are niciun element, reducerea este 0. Dacă matricea are un element, reducerea este valoarea acelui
element. Pentru orice alte cazuri, matricea se subîmparte în 4 matrici prin tăierea ei în cruce, prin mijlocul matricii.
Reducerea va fi maximul reducerilor celor două matrici superioare, minus minimul reducerilor celor două matrici
inferioare. Să se calculeze reducerea unei matrici de dimensiuni m,n citită de la tastatură.*/

#include <stdio.h>

int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y){
    return x > y ? x : y;
}

int reducere(int a[100][100], int x1, int x2, int y1, int y2){ 
    int ss, sd, js, jd;

    if (x2 == x1 && y2 == y1)
        return a[y1][x1];

    ss = reducere(a, x1, (x2 - x1) % 2 == 0 ? (x2 + x1) / 2 - 1 : (int)(x2 + x1) / 2, y1, (y2 - y1) % 2 == 0 ? (y2 + y1) / 2 - 1 : (int)(y2 + y1) / 2);
    sd = reducere(a, (x2 - x1) % 2 == 0 ? (x2 + x1) / 2 + 1 : (int)(x2 + x1) / 2 + 1, x2, y1, (y2 - y1) % 2 == 0 ? (y2 + y1) / 2 - 1 : (int)(y2 + y1) / 2);
    js = reducere(a, x1, (x2 - x1) % 2 == 0 ? (x2 + x1) / 2 - 1 : (int)(x2 + x1) / 2, (y2 - y1) % 2 == 0 ? (y2 + y1) / 2 + 1 : (int)(y2 + y1) / 2 + 1, y2);
    jd = reducere(a, (x2 - x1) % 2 == 0 ? (x2 + x1) / 2 + 1 : (int)(x2 + x1) / 2 + 1, x2, (y2 - y1) % 2 == 0 ? (y2 + y1) / 2 + 1 : (int)(y2 + y1) / 2 + 1, y2);
    return max(ss, sd) - min(js, jd);
}

int main(){
    int a[100][100] = {{1, 2, 2, 4}};
    int x = reducere(a, 0, 3, 0, 1);
    printf("%d", x);
}
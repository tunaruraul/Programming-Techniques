/*Aplicația 13.3: Se cere un 0<n<=100 și apoi n valori reale, fiecare reprezentând volumul unui obiect. În final se
cere v, volumul unei cutii. Se cere să se umple cutia cu unele dintre obiecte date, astfel încât volumul ei să fie
utilizat în mod optim.*/

#include <stdio.h>

int bestVol[100], cVol[100], bv = 0, n, vol[100], v, cv = 0;
FILE *f;

int good(int k){
    if (cv > v)
        return 0;
    for (int i = 0; i < k; i++)
        if (cVol[i] >= cVol[k])
            return 0;
    return 1;
}

void solution(int k){

    if (cv > bv){
        bv = cv;
        for (int i = k; i < n; i++)
            bestVol[i] = 0;
        for (int i = 0; i < k; i++)
            bestVol[i] = cVol[i];
    }
}

void print(){
    printf("volum maxim:%d\n", bv);
    for (int i = 0; i < n; i++)
        if (bestVol[i])
            printf("%d ", vol[bestVol[i] - 1]);
        else
            break;
}

void back(int k){
    for (int i = 0; i <= n; i++){
        if (i == n)
            solution(k);
        else{
            cVol[k] = (i + 1);
            cv = cv + vol[i];
            if (good(k))
                if (k == n)
                    solution(k);
                else
                    back(k + 1);
            cv = cv - vol[i];
        }
    }
}

int main(){
    f = fopen("input3.in", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", vol + i);
    fscanf(f, "%d", &v);

    back(0);
    print();
}
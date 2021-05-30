/*Aplicația 13.6: Se cere d de tip întreg reprezentând lungimea unei drepte și 0<n<=100 un număr de segmente. În
câte feluri se poate împărți dreapta dată în n segmente consecutive, având fiecare lungimi întregi pozitive, astfel
încât fiecare segment să fie strict mai mare decât cel de dinaintea sa?*/

#include <stdio.h>

int d, n, c = 0;
int sol[100];

int good(int k){
    if (k >= 1)
        return sol[k] > sol[k - 1];
    else
        return 1;
}

void solution(){
    int s = 0;
    for (int i = 0; i < n; i++)
        s += sol[i];
    if (s != d)
        return;
    for (int i = 0; i < n; i++)
        printf("%d ", sol[i]);
    printf("\n");
    c++;
}

void back(int k){
    for (int i = 1; i <= d; i++){
        sol[k] = i;
        if (good(k))
            if (k == n - 1)
                solution();
            else
                back(k + 1);
    }
}

int main(){
    scanf("%d%d", &d, &n);
    back(0);
    printf("%d", c);
}
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char Nume[30];
    char Prenume[30];
    char Sex[20];
    int inaltime;
}persoana;
persoana*N;
persoana citire(persoana temp){
    char nume[30],prenume[30],sex[20];
    int inaltime;
    printf("Nume=");scanf("%s",nume);
    printf("Prenume=");scanf("%s",prenume);
    printf("Sex=");scanf("%s",sex);
    printf("Inaltime=");scanf("%d",inaltime);
    strcpy(temp.Nume,nume);
    strcpy(temp.Prenume,prenume);
    strcpy(temp.Sex,sex);
    temp.inaltime=inaltime;
    return temp;
}
int main()
{
    int n;
    printf("n=");scanf("%d",&n);getchar();
     if((N=(persoana*)malloc(26*sizeof(persoana)))==NULL){
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
        }
    for(int i=0;i<n;i++){
        N[i]=citire(N[i]);
    }
    return 0;
}

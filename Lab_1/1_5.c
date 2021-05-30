#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char litera;
    int punctaj;
}lit;
lit*N;
int n;
int punctaj(char*sir,lit*V){
    int s=0;
    for(int i=0;i<strlen(sir);i++){
            for(int j=0;j<n;j++){
                if(sir[i]==V[j].litera)
                    s=s+V[j].punctaj;
            }
        }
    return s;
}
void eliberare(lit*elib){
    free(elib);
}
int main()
{
    char sir[256]="\o";
    printf("n=");scanf("%d",&n);getchar();
     if((N=(lit*)malloc(26*sizeof(lit)))==NULL){
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
        }
    for(int i=0;i<n;i++)
    {
        printf("litera=");N[i].litera=getchar();
        printf("punctajul literei %c=",N[i].litera);scanf("%d",&N[i].punctaj);getchar();
    }
    int s=0;
    printf("Introduceti sirul:");scanf("%s",sir);
    while(strcmp(sir,"gata")!=0){
        s=s+punctaj(sir,N);
        printf("Introduceti sirul:");scanf("%s",sir);
    }
    printf("\n%d",s);
    eliberare(N);
    return 0;
}

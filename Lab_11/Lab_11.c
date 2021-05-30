#include "Functions.h"
#include "Utils.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    char s1[MAX_SIR], s2[MAX_SIR], sir[MAX_SIR];
    for(;;){
        printf("\n1. concatenare\n");
        printf("2. extract\n");
        printf("3. trim\n");
        printf("4. iesire\n");
        int op;
        printf("\noptiune : ");
        scanf("%d", &op);
        switch(op) {
            case 1:{
                getchar();
                citesteText("sir1", s1, MAX_SIR);
                citesteText("sir2", s2, MAX_SIR);
                printf("%s\n", strCat(s1, s2));
                break;
            }

            case 2:{
                getchar();
                citesteText("sir", sir,MAX_SIR);
                printf("%s\n", strExtract(sir+3, sir+3));
                break;
            }

            case 3:{
                getchar();
                citesteText("sir", sir, MAX_SIR);
                printf("%s\n", strTrim(sir));
                break;
            }

            case 4:{
                return 0;
            }

            default:{
                printf("\nOptiune invalida!\n");
            }
        }
    }
}

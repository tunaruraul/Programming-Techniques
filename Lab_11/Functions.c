#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *strCat(char *s1, char *s2){
    char *sir = (char*)malloc((strlen(s1)+strlen(s2))*sizeof(char));
    check_mem_alloc(sir);
    strcpy(sir, strcat(s1, s2));
    return sir;
}

char *strExtract(char *i, char *j){
    int poz = 0;
    char *sirD = (char*)malloc(j - i + 1);
    check_mem_alloc(sirD);
    while (i != j){
        sirD[poz++] = i[0];
        i++;
    }
    sirD[poz] = 0;
    return sirD;
}

char *strTrim(char *sir){
    char *s = (char*)malloc(strlen(sir)*sizeof(char));
    check_mem_alloc(s);
    strcpy(s, sir);
    while(s[0] == ' ' || s[0] =='\n' || s[0] =='\r' || s[0] =='\t')
        strcpy(s, s+1);

    while(s[strlen(s)-1] ==' ' || s[strlen(s)-1] =='\n' || s[strlen(s)-1] =='\r' || s[strlen(s)-1] =='\t')
        s[strlen(s)-1] = '\0';

    s=(char*)realloc(s, strlen(s)+1);
    return s;
}

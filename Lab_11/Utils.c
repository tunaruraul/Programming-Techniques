#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citesteText(const char *text, char *dst, int mx){
    printf("%s: ", text);
    fgets(dst, mx, stdin);
    dst[strcspn(dst,"\r\n")]='\0';
}

void check_mem_alloc(const char *s){
    if(s == NULL){
        printf("Err");
        exit(EXIT_FAILURE);
    }
}

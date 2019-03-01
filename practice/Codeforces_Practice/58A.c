#include <stdio.h>

int main(void){

    int i,n;

    char * result = "hello";

    char test[100];

    scanf("%s", test);
    
    for(i=0; *result != '\0' && test[i] != '\0'; i++){
        if(*result == test[i]){
            result++;
        }
    }

    if(*result == '\0') printf("YES\n");
    else{ printf("NO\n");}
    return 0;
}
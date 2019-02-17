#include <stdio.h>
#include <stdlib.h>

int main(void){

    int temp;

    printf("1\n");
    fflush(stdout);

    scanf("%d", &temp);

    if (temp==2) printf("3\n");
    else printf("2\n");
    fflush(stdout);

    return 0;
}
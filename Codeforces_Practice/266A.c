#include <stdio.h>

int main(void){

    int n, i;

    scanf("%d", &n);

    char word[n];

    scanf("%s", word);

    char *curr = word;
    char *next = curr+1;
    int count = 0;

    while(*curr != '\0'){
        if(*next == *curr){
            count++;
            next++;
        }
        else{
            curr = next;
            next++;
        }
    }

    printf("%d\n", count);
    return 0;
}
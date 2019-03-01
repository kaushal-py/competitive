#include <stdio.h>

int main(void){

    char word[1000];

    scanf("%s", word);

    int i;

    if(word[0] > 'Z') word[0] = word[0] - 'a' + 'A';

    printf("%s\n", word);
    return 0;
}
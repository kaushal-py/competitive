#include <stdio.h>

int main(void){

    int alphabet[26] = {0};

    char username[100];

    scanf("%s", username);

    for(int i=0; username[i] != '\0'; i++){
        alphabet[username[i]-'a'] = 1;
    }

    int total=0;

    for(int i=0; i<26; i++)
        if(alphabet[i]) total++;
    
    if(total%2 == 0) printf("CHAT WITH HER!\n");
    else printf("IGNORE HIM!\n");
    return 0;
}
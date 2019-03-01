#include <stdio.h>

int main(void){

    int t;
    int i, j, k, n;
    int isSpecial;
    char s[200];

    scanf("%d", &t);

    while(t--){

        int count_sp = 0;

        scanf("%d", &n);
        int table[n][26];

        for(j=0; j<n; j++)
            for(k=0; k<26; k++)
                table[j][k] = 0;
        
        for(i=0; i<n; i++){
            scanf("%s", s);
            j=0;
            while(s[j] != '\0'){
                table[i][s[j]-'a'] = 1;
                j++;
            }
        }

        for(k=0; k<26; k++){
            isSpecial = 1;
            for(j=0; j<n; j++){
                if(table[j][k] != 1){
                    isSpecial = 0;
                }

            }
            if(isSpecial == 1) count_sp++;
        }
        printf("%d\n", count_sp);
            
    }

    return 0;
}
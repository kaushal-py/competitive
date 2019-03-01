#include <stdio.h>

int main(void){

    int n;
    scanf("%d", &n);

    int divisors[] = {4,7,47,74,447,474,477,747,774};

    int flag = 0;

    for(int i=0; i<9; i++){
        if (n % divisors[i] == 0){
            flag=1;
            break;
        }
    }

    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}
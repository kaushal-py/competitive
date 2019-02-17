#include <stdio.h>

int main(void){

    int n, k;
    int temp;
    int i;

    scanf("%d%d", &n, &k);

    for(i=0; i<n; i++){
        scanf("%d", &temp);
        if (temp < k) printf("Bad boi\n");
        else printf("Good boi\n");
    }


    return 0;
}
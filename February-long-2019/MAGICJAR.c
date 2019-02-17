#include <stdio.h>

int main(void){

    int t;
    int i,n;

    scanf("%d", &t);

    while(t--){

        int jars = 0;
        int temp;

        scanf("%d", &n);

        for(i=0; i<n; i++){
            scanf("%d", &temp);
            jars += (temp-1);
        }

        printf("%d\n", jars+1);
    }

    return 0;
}
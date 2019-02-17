#include <stdio.h>

int main(void){

    int t;
    int i,j,k,n;

    int prev, next;
    int max_shield = -1;


    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        int a[n], d[n];
        max_shield = -1;

        for(i=0; i<n; i++) scanf("%d", a+i);
        for(i=0; i<n; i++) scanf("%d", d+i);

        for(i=0; i<n; i++){
            
            prev = (i+n-1)%n;
            next = (i+n+1)%n;

            if(((a[prev] + a[next]) < d[i]) && (d[i]>max_shield))
                max_shield = d[i];
            
        }

        printf("%d\n", max_shield);


    }

    return 0;
}
#include <stdio.h>

int main(void){

    int n,a,b, i;

    scanf("%d", &n);

    int max_size = 0, curr_size = 0;

    for(i=0; i<n; i++){

        scanf("%d %d", &a, &b);

        curr_size += (b-a);

        if (curr_size > max_size) max_size=curr_size;
    }

    printf("%d\n", max_size);

    return 0;
}
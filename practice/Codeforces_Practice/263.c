#include <stdio.h>

int sub_mod(int a, int b){
    if (a>=b) return a-b;
    else return b-a;
}

int main(void){

    int i, j;
    int pos_i, pos_j;
    int temp;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            scanf("%d", &temp);
            if (temp == 1){
                pos_i = i;
                pos_j = j;
            }
        }
    }

    printf("%d\n", sub_mod(pos_i,2) + sub_mod(pos_j,2));

    return 0;
}
#include <stdio.h>

int main(void){

    int seats[4];
    int i;

    for(i=0; i<4; i++) seats[i] = 0;

    int n;
    int temp;
    scanf("%d", &n);

    for(int j=0; j<n; j++){

        scanf("%d", &temp);

        int cond = 1;

        for(int k=temp; k<4; k++){

            if(seats[k] != 0){
                cond = 0;
                seats[k] -= 1;
                seats[k-temp] += 1;
                break;
            }
        }

        if(cond){
            seats[4-temp] += 1;
        }

        // for(int x=0; x<4; x++){
        //     printf("%d ", seats[x]);
        // }
        // printf("\n");
    }

    int total=0;

    for(i=0; i<4; i++){
        total += seats[i];
    }

    printf("%d\n", total);
    return 0;
}
#include <stdio.h>

int main(){
    int price[15] = {100, 102, 105, 103, 98, 96, 99, 104, 110, 108,
    112, 118, 115, 111, 117};
    int max = 0;
    int days[]={};
    int best_days[] = {};
    int count = 0;
    for(int x=0; x <14; x++){
        days[x] = x + 1;
    }
    for(int i=0; i < 14; i++){
        if (price[i] < price[i+1]){
            count++;  
            printf("%d,%d\n", price[i], price[i+1]);
            printf("%d\n", count);
        }
        else{
            if (max < count){
            max = count;
            count = 0;
        }
            else{
                count = 0;
            }
        }
    }
    printf("Самый длинный период роста: %d", max);


    return 0;
}
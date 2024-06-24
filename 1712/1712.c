#include<stdio.h>

int main(){

    int fixedCost;
    int changedCost;
    int sellPrice;
    
    scanf("%d %d %d", &fixedCost, &changedCost, &sellPrice);

    if(changedCost >= sellPrice){
        printf("-1");
    }
    else{
        printf("%d\n", fixedCost/(sellPrice-changedCost)+1);
    }
    return 0;
}
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize){
    int expected[100];
    int exSize = sizeof(expected)/sizeof(expected[0]);
    int l=0;
    

    for(int i=0; i<numsSize; i++){
        for(int j = 0; j< exSize ; j++){
            if(nums[i] != expected[j]){
                expected[l]= nums[i];
                l++;
            }
            else{
                continue;
            }
        }      
    } 
    return expected;  
}
int main(){
    int nums[100];
    int numsSize;
    for(int i = 0; i < numsSize; i++){
        printf("enter array in asc: ");
        scanf("%d", &nums[i]);
    }
    int exp[100] = removeDuplicates(nums,numsSize);
    int k = sizeof(exp)/sizeof(exp[0]);
    printf("k = %d",k);
    for(int i = 0; i<k; i++){
        printf("%d" , exp[i]);

    }
    
   
}
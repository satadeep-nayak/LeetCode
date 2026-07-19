int removeDuplicates(int* nums, int numsSize) {

    int k = 0 ;

    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] > nums[k]){
            if(i == k + 1){
                k++;
            }
            else{
                k++;
                nums[k] = nums[i];
            }
        }
    }
    return k + 1;
}
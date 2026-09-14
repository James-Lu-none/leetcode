void reverse(int* nums, int left, int right) {
    while(right>left) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    return;
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2) return;
    int i = numsSize-2;
    while (i>=0) {
        if (nums[i] >= nums[i+1]) {
            i--;
        } else {
            break;
        }
    }
    if(i < 0) {
        reverse(nums, 0, numsSize-1);
        return;
    }

    for(int j = numsSize-1; j>i; j--) {
        if(nums[j]>nums[i]){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            break;
        }
    }
    reverse(nums, i+1, numsSize-1);
    return;
}
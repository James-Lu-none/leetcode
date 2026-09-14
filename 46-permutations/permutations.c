/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void reverse(int* nums, int left, int right) {
    while(right>left){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        right--;
        left++;
    }
    return;
}

bool next_premute(int* nums, int n){
    int i = n-2;
    while(i>=0) {
        if(nums[i] < nums[i+1]) {
            break;
        } else {
            i--;
        }
    }

    if(i<0) return false;

    // find first greater
    for(int j=n-1; j>i; j--) {
        if (nums[j]>nums[i]) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            break;
        }
    }

    reverse(nums, i+1, n-1);
    return true;
}
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int** result = NULL;
    *returnSize = 0;
    if(numsSize < 2) {
        *returnColumnSizes = malloc(sizeof(int)*((*returnSize)+1));
        (*returnColumnSizes)[0] = numsSize;
        result = malloc(sizeof(int*)*((*returnSize)+1));
        result[0] = malloc(sizeof(int)*numsSize);
        result[0][0] = nums[0];
        (*returnSize)++;
        return result;
    }

    bool flag = true;
    while(flag) {
        int i = (*returnSize);
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = numsSize;

        result = realloc(result, sizeof(int*)*(i+1));
        result[i] = malloc(sizeof(int)*numsSize);
        memcpy(result[*returnSize], nums, sizeof(int)*numsSize);
        (*returnSize)++;
        flag = next_premute(nums, numsSize);
    }
    return result;
}
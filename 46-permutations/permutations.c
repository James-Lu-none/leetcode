// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */

// void reverse(int* nums, int left, int right) {
//     while(right>left){
//         int temp = nums[left];
//         nums[left] = nums[right];
//         nums[right] = temp;
//         right--;
//         left++;
//     }
//     return;
// }

// bool next_premute(int* nums, int n){
//     int i = n-2;
//     while(i>=0) {
//         if(nums[i] < nums[i+1]) {
//             break;
//         } else {
//             i--;
//         }
//     }

//     if(i<0) return false;

//     // find first greater
//     for(int j=n-1; j>i; j--) {
//         if (nums[j]>nums[i]) {
//             int temp = nums[i];
//             nums[i] = nums[j];
//             nums[j] = temp;
//             break;
//         }
//     }

//     reverse(nums, i+1, n-1);
//     return true;
// }
// int cmp(const void* a, const void* b) {
//     return (*(int*)a - *(int*)b);
// }
// int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//     qsort(nums, numsSize, sizeof(int), cmp);

//     int** result = NULL;
//     *returnSize = 0;
//     if(numsSize < 2) {
//         *returnColumnSizes = malloc(sizeof(int)*((*returnSize)+1));
//         (*returnColumnSizes)[0] = numsSize;
//         result = malloc(sizeof(int*)*((*returnSize)+1));
//         result[0] = malloc(sizeof(int)*numsSize);
//         result[0][0] = nums[0];
//         (*returnSize)++;
//         return result;
//     }

//     bool flag = true;
//     while(flag) {
//         int i = (*returnSize);
//         *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(i+1));
//         (*returnColumnSizes)[i] = numsSize;

//         result = realloc(result, sizeof(int*)*(i+1));
//         result[i] = malloc(sizeof(int)*numsSize);
//         memcpy(result[*returnSize], nums, sizeof(int)*numsSize);
//         (*returnSize)++;
//         flag = next_premute(nums, numsSize);
//     }
//     return result;
// }

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive backtracking function
void backtrack(int* nums, int numsSize, int start, int** result, int* returnSize) {
    // Base Case: If the start index reaches the end, a valid permutation is formed
    if (start == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], nums, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }

    // keep current selection (dont swap, case where start==i in the for loop) 
    backtrack(nums, numsSize, start+1, result, returnSize); 

    // choose 
    for (int i = start+1; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);              // Make choice (swap)
        backtrack(nums, numsSize, start + 1, result, returnSize); // Recurse
        swap(&nums[start], &nums[i]);              // Undo choice (backtrack)
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned arrays and *returnColumnSizes array must be lethally malloced.
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Total number of permutations is N! (N factorial)
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        totalPermutations *= i;
    }

    // Allocate memory for the main result tracking row arrays
    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    
    // Allocate memory for returnColumnSizes, tracking the size of each row
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));
    
    *returnSize = 0; // Initialize return size tracker

    // Begin the recursive backtracking
    backtrack(nums, numsSize, 0, result, returnSize);

    // Set the column sizes for all generated entries
    for (int i = 0; i < totalPermutations; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    return result;
}
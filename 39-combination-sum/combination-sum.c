/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* tempResult = NULL;
int tempSize = 0;
void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int*** results, int start){
    if (target == 0) {
        // update results
        (*results) = realloc(*results, sizeof(int*)*((*returnSize)+1));
        (*results)[*returnSize] = malloc(sizeof(int)*tempSize);
        memcpy((*results)[*returnSize], tempResult, sizeof(int)*tempSize);

        // update column sizes
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*((*returnSize)+1));
        (*returnColumnSizes)[*returnSize] = tempSize;

        (*returnSize)++;
        return;
    }
    for(int i=start; i<candidatesSize; i++){
        int choice = candidates[i];
        if(target-choice >= 0) {
            // printf("%d\n", tempSize+1);
            tempResult = realloc(tempResult, sizeof(int)*(tempSize+1));
            tempResult[tempSize] = choice;
            tempSize++;
            backtrack(candidates, candidatesSize, target-choice, returnSize, returnColumnSizes, results, i);
            tempSize--;
        }
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** results=NULL;
    *returnColumnSizes = NULL;
    *returnSize = 0;
    tempSize = 0;
    tempResult = NULL;
    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, &results, 0);
    return results;
}
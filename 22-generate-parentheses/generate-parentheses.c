/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(int n, int start, int lefts, int rights, char* tempResult, int* returnSize, char*** results) {
    if (start == 2 * n) {
        tempResult[start] = '\0';
        
        char** temp_results = realloc(*results, sizeof(char*) * ((*returnSize) + 1));
        if (temp_results == NULL) {
            return; 
        }
        *results = temp_results;
        
        (*results)[*returnSize] = malloc(sizeof(char) * (2 * n + 1));
        strcpy((*results)[*returnSize], tempResult);
        (*returnSize)++;
        return;
    }

    if (lefts < n) {
        tempResult[start] = '(';
        backtrack(n, start + 1, lefts + 1, rights, tempResult, returnSize, results);
    }
    
    if (rights < lefts) {
        tempResult[start] = ')';
        backtrack(n, start + 1, lefts, rights + 1, tempResult, returnSize, results);
    }
}


char** generateParenthesis(int n, int* returnSize) {
    char** results = NULL;
    *returnSize = 0;
    char* tempResult = malloc(sizeof(char)*(n*2+1));
    backtrack(n, 0, 0, 0, tempResult, returnSize, &results);
    return results;
}
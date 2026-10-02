/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int lefts = 0;
int rights = 0;
char* tempResult = NULL;
void backtrack(int n, int start, int* returnSize, char*** results) {
    if(start == 2*n) {
        tempResult[start] = '\0';
        *results = realloc(*results, sizeof(char*)*((*returnSize)+1));
        (*results)[*returnSize] = malloc(sizeof(char)*(2*n+1));
        strcpy((*results)[*returnSize], tempResult);
        (*returnSize)++;
        return;
    }

    // try add '('
    if(lefts<n) { // only add '(' if number of '(' hasn't pass half
        lefts++;
        tempResult[start] = '(';
        backtrack(n, start+1, returnSize, results);
        lefts--; // revert change
    }
    
    // try add ')'
    if(rights<lefts) { // only add ')' if there's more '('
        rights++;
        tempResult[start] = ')';
        backtrack(n, start+1, returnSize, results);
        rights--; // revert change
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** results = NULL;
    *returnSize = 0;
    tempResult = malloc(sizeof(char)*(n*2+1));
    backtrack(n, 0, returnSize, &results);
    return results;
}
#include <stdlib.h>
#include <string.h>

// 卡特蘭數前 9 項（n 範圍通常在 1 到 8）
const int CATALAN[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};

void backtrack(int n, int start, int lefts, int rights, char* tempResult, int* returnSize, char** results) {
    if (start == 2 * n) {
        tempResult[start] = '\0';
        // 直接寫入已配置好的空間，不使用 realloc
        results[*returnSize] = malloc(sizeof(char) * (2 * n + 1));
        strcpy(results[*returnSize], tempResult);
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
    *returnSize = 0;
    
    // 根據卡特蘭數，直接預分配合適的二維陣列大小
    int total_combinations = CATALAN[n]; 
    char** results = malloc(sizeof(char*) * total_combinations);
    
    char* tempResult = malloc(sizeof(char) * (n * 2 + 1));
    
    // 注意：這裡傳入的是 results (char**)，不再需要 &results (char***)
    backtrack(n, 0, 0, 0, tempResult, returnSize, results);
    
    free(tempResult);
    return results;
}

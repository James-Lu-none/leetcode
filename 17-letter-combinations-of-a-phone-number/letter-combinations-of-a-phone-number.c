/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const char *phone_map[] = {
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(char* digits, int index, int n, char* current, char** result, int* returnSize) {
    if (index == n) {
        current[n] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    // 取得當前數字所對應的字母集合（'2' 對應 index 0）
    const char* letters = phone_map[digits[index] - '2'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i]; // 選擇當前字元
        backtrack(digits, index + 1, n, current, result, returnSize); // 遞迴探索下一層
    }
}
char** letterCombinations(char* digits, int* returnSize) {

    int n = strlen(digits);
    *returnSize = 1;
    for(int i=0; i<n; i++){
        (*returnSize) *= strlen(phone_map[digits[i]-'2']);
    }
    char** result = malloc(sizeof(char*)*(*returnSize));
    for(int i=0; i<(*returnSize); i++){
        result[i] = malloc(sizeof(char)*(n+1));
    }
    char* curr = malloc(sizeof(char)*(n+1));
    *returnSize = 0;
    backtrack(digits, 0, n, curr, result, returnSize);
    return result;
}
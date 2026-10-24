#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[TABLE_SIZE];
} HashMap;

// 簡單的雜湊函數
int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void put(HashMap* map, int key, int value) {
    int index = hash(key);
    // get head of linked list at bucket index "index"
    Node* curr = map->buckets[index];
    
    // 
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    // insert new at head
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int get(HashMap* map, int key, int* foundValue) {
    int index = hash(key);
    Node* curr = map->buckets[index];
    if (curr == NULL) {
        return 0;
    }
    
    while (curr != NULL) {
        if (curr->key == key) {
            *foundValue = curr->value;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;
    HashMap map;
    memset(&map, 0, sizeof(HashMap));
    int sum = 0;
    int result = 0;
    put(&map, 0, 1);
    for (int i=0;i<numsSize;i++){
        sum+=nums[i];
        int foundValue = 0;
        if(get(&map, sum-k, &foundValue) == 1){
            result += foundValue;
        }

        int currentvalue = 0;
        if(get(&map, sum, &currentvalue) == 1){
            put(&map, sum, currentvalue+1);
        } else {
            put(&map, sum, 1);
        }
    }
    return result;
    // int result = 0;
    // int currentSum = 0;
    // int left = 0;
    // int *prefixsums = malloc((numsSize+1)*sizeof(int));
    
    // prefixsums[0] = 0;
    // prefixsums[1] = nums[0];
    // for (int i=1;i<numsSize;i++){
    //     prefixsums[i+1] = nums[i] + prefixsums[i];
    // }
    // for (int i=numsSize;i>=0;i--){
    //     for (int j=0;j<i;j++){
    //         printf("%d, %d\n", j, i);
    //         // result++; 
    //         if (prefixsums[i]-prefixsums[j] == k) {
    //             result++; 
    //         }
    //     }
    // }
    // free(prefixsums);
    // return result;
}
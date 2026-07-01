/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

#define SIZE 10007

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[SIZE] = {NULL};

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int h = hash(complement);

        Node* curr = table[h];
        while (curr) {
            if (curr->key == complement) {
                int* ans = (int*)malloc(2 * sizeof(int));
                ans[0] = curr->value;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            }
            curr = curr->next;
        }

        h = hash(nums[i]);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = table[h];
        table[h] = newNode;
    }

    *returnSize = 0;
    return NULL;
}
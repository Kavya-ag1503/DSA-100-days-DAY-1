#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue functions
struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;

void enqueue(struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

struct Node* dequeue() {
    if (front == NULL) return NULL;
    struct QueueNode* temp = front;
    struct Node* treeNode = temp->treeNode;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return treeNode;
}


struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[0];
    root->left = root->right = NULL;

    enqueue(root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();
        if (curr == NULL) continue;

        // Left child
        if (i < n && arr[i] != -1) {
            struct Node* leftChild = (struct Node*)malloc(sizeof(struct Node));
            leftChild->data = arr[i];
            leftChild->left = leftChild->right = NULL;
            curr->left = leftChild;
            enqueue(leftChild);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            struct Node* rightChild = (struct Node*)malloc(sizeof(struct Node));
            rightChild->data = arr[i];
            rightChild->left = rightChild->right = NULL;
            curr->right = rightChild;
            enqueue(rightChild);
        }
        i++;
    }

    return root;
}


int height(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);

    printf("%d\n", height(root));

    return 0;
}
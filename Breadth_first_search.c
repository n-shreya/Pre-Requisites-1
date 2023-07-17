#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the tree
TreeNode* insertNode(TreeNode* root, int data) {
    // If the tree is empty, assign a new node address to the root
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // (NULL) space for the new node
    TreeNode* temp;
    if (data <= root->data) {
        temp = insertNode(root->left, data);
        root->left = temp;
    } else {
        temp = insertNode(root->right, data);
        root->right = temp;
    }
    return root;
}

// Function to perform breadth-first search (BFS) traversal
void breadthFirstSearch(TreeNode* root, FILE* outputFile) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    TreeNode* queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue the front node and print its data
        TreeNode* currentNode = queue[front++];
        fprintf(outputFile, "%d ", currentNode->data);

        // Enqueue the left child
        if (currentNode->left != NULL)
            queue[rear++] = currentNode->left;

        // Enqueue the right child
        if (currentNode->right != NULL)
            queue[rear++] = currentNode->right;
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Generate random numbers and store them in the input file
    FILE* inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    srand(time(NULL));  // Initialize random seed
    TreeNode* root = NULL;

    // Generate random numbers and insert them into the tree
    for (int i = 0; i < numNodes; i++) {
        int num = rand() % 100;
        fprintf(inputFile, "%d ", num);
        root = insertNode(root, num);
    }

    fclose(inputFile);

    // Perform BFS traversal and store the result in the output file
    FILE* outputFile = fopen("BFS.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    breadthFirstSearch(root, outputFile);
    fclose(outputFile);

    printf("BFS traversal is completed and stored in BFS.txt.\n");

    return 0;
}

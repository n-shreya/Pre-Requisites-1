#include <stdio.h>
#include <stdlib.h>

// Structure for a customer order
struct Order {
    int orderId;
    int distance;
    struct Order* left;
    struct Order* right;
    int height;
};

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the height of a node
int height(struct Order* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to create a new order node
struct Order* createOrder(int orderId, int distance) {
    struct Order* order = (struct Order*)malloc(sizeof(struct Order));
    order->orderId = orderId;
    order->distance = distance;
    order->left = NULL;
    order->right = NULL;
    order->height = 1;
    return order;
}

// Function to perform a right rotation
struct Order* rightRotate(struct Order* y) {
    struct Order* x = y->left;
    struct Order* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
struct Order* leftRotate(struct Order* x) {
    struct Order* y = x->right;
    struct Order* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Order* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a new order into the AVL tree
struct Order* insertOrder(struct Order* node, int orderId, int distance) {
    if (node == NULL)
        return createOrder(orderId, distance);

    if (orderId < node->orderId)
        node->left = insertOrder(node->left, orderId, distance);
    else if (orderId > node->orderId)
        node->right = insertOrder(node->right, orderId, distance);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && orderId < node->left->orderId)
        return rightRotate(node);

    if (balance < -1 && orderId > node->right->orderId)
        return leftRotate(node);

    if (balance > 1 && orderId > node->left->orderId) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && orderId < node->right->orderId) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the minimum value node in a given AVL tree
struct Order* minValueNode(struct Order* node) {
    struct Order* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with a given orderId from the AVL tree
struct Order* deleteOrder(struct Order* root, int orderId) {
    if (root == NULL)
        return root;

    if (orderId < root->orderId)
        root->left = deleteOrder(root->left, orderId);
    else if (orderId > root->orderId)
        root->right = deleteOrder(root->right, orderId);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Order* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Order* temp = minValueNode(root->right);
            root->orderId = temp->orderId;
            root->right = deleteOrder(root->right, temp->orderId);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for an order with a given orderId in the AVL tree
struct Order* searchOrder(struct Order* root, int orderId) {
    if (root == NULL || root->orderId == orderId)
        return root;

    if (orderId < root->orderId)
        return searchOrder(root->left, orderId);

    return searchOrder(root->right, orderId);
}

// Function to traverse the AVL tree in-order and store the orders in a file
void storeOrdersInFile(struct Order* root, FILE* file) {
    if (root == NULL)
        return;

    storeOrdersInFile(root->left, file);
    fprintf(file, "Order ID: %d, Distance: %d\n", root->orderId, root->distance);
    storeOrdersInFile(root->right, file);
}

// Function to display the AVL tree and store it in a file
void displayOrders(struct Order* root) {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (root == NULL) {
        fprintf(file, "No orders in the AVL tree.\n");
    } else {
        storeOrdersInFile(root, file);
    }

    fclose(file);
    printf("AVL tree displayed and stored in output.txt.\n");
}

int main() {
    struct Order* root = NULL;
    int choice, orderId, distance;

    do {
        printf("1. Add an order\n");
        printf("2. Remove an order\n");
        printf("3. Search for an order\n");
        printf("4. Display AVL tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order ID: ");
                scanf("%d", &orderId);
                printf("Enter distance: ");
                scanf("%d", &distance);
                root = insertOrder(root, orderId, distance);
                printf("Order added successfully.\n");
                break;

            case 2:
                printf("Enter order ID to remove: ");
                scanf("%d", &orderId);
                root = deleteOrder(root, orderId);
                printf("Order removed successfully.\n");
                break;

            case 3:
                printf("Enter order ID to search: ");
                scanf("%d", &orderId);
                struct Order* result = searchOrder(root, orderId);
                if (result == NULL)
                    printf("Order not found.\n");
                else
                    printf("Order found: Order ID: %d, Distance: %d\n", result->orderId, result->distance);
                break;

            case 4:
                displayOrders(root);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}

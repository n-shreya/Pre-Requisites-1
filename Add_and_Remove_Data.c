#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the linked list
struct Node
{
    int data;
    struct Node* next;
};

// Structure for the linear queue
struct Queue
{
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data)
{
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, set the new node as both front and rear
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Otherwise, add the new node at the rear and update the rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void display_queue(int arr[],struct Queue *queue,int n)
{
    int i;
    struct Queue* temp;
    temp=queue->front;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        temp= queue->rear;
    }
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);
    int a[100];
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter %d value of enqueue:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        enqueue(&queue, a[i]);
    }
    display_queue(a,&queue,n);
    return 0;
}


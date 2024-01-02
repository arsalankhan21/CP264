/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
  // Create a new node with the given data
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = np->data;
  newNode->type = np->type;
  newNode->next = NULL;

  if (qp->rear == NULL) {
    // If the queue is empty, make the new node the front and rear
    qp->front = newNode; // Set the front pointer to the new node
    qp->rear = newNode; // Set the rear pointer to the new node
  } else {
    // Add the new node to the rear and update the rear pointer
    qp->rear->next = newNode; // Set the next pointer of the rear node to the new node
    qp->rear = newNode; // Set the rear pointer to the new node
  }

  // Increment the length of the queue
  qp->length++; 
}

NODE *dequeue(QUEUE *qp) {
  if (qp->front == NULL) {
    // If the queue is empty, return NULL
    return NULL;
  }

  // Store the front node and its data
  NODE *frontNode = qp->front; // Store the front node
  int frontData = frontNode->data; // Store the front data
  int frontType = frontNode->type; // Store the front type

  // Move the front pointer to the next node
  qp->front = qp->front->next;

  // If the front becomes NULL, the queue is now empty, so update the rear as well
  if (qp->front == NULL) {
    qp->rear = NULL;
  }

  // Decrement the length of the queue
  qp->length--;

  // Free the memory occupied by the front node
  free(frontNode);

  // Create a new node and assign the front data to it
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = frontData;
  newNode->type = frontType;
  newNode->next = NULL;

  // Return the new node
  return newNode;
}

void queue_clean(QUEUE *qp) {
  // Call the clean() function in common.h to clean the data stored in each node
  clean(&(qp->front));

  // Reset the front, rear, and length of the queue
  qp->front = NULL;
  qp->rear = NULL;
  qp->length = 0;
}

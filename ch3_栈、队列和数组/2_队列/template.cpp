#include <bits/stdc++.h>
using namespace std;

#define maxsize 5
typedef struct {
  int data[maxsize];
  int front, rear;
}Queue;

void initQueue(Queue &Q) {
  Q.front = Q.rear = 0;
}

bool isEmpty(Queue &Q) {
  return Q.front == Q.rear;
}

bool isFull(Queue &Q) {
  return Q.front == (Q.rear + 1) % maxsize;
}

bool enqueue(Queue &Q, int x) {
  if (isFull(Q)) {
    cout << "队列满" << endl;
    return false;
  }

  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % maxsize;
  return true;
}

bool dequeue(Queue &Q, int &x) {
  if (isEmpty(Q)) {
    cout << "队列空" << endl;
    return false;
  }

  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % maxsize;
  return true;
}

/***************  3.2.6, 01  ***************/
/************  22/05/08 Mancuoj  ***********/

int main() {
  Queue Q;
  initQueue(Q);
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  enqueue(Q, 4);
  enqueue(Q, 5);      // 队满
  enqueue(Q, 6);      // 队满
  int x;
  dequeue(Q, x);
  cout << x << endl;    // 1
  dequeue(Q, x);
  cout << x << endl;    // 2
  return 0;
}

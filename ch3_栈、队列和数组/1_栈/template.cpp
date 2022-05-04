#include <bits/stdc++.h>
#define maxsize 100
using namespace std;

typedef struct {
  int stack[maxsize];
  int top;
} stk;
stk s;
s.top = -1;

// 用数组模拟栈
int stk[100];
int top = -1;

bool isEmpty() {
  return top == -1;
}

void push(int x) {
  stk[++top] = x;
}

int pop() {
  return stk[top--];
}

int getTop() {
  return stk[top];
}

/***************  3.1.5, 03  ***************/
/************  22/05/02 Mancuoj  ***********/

int main() {
  
  return 0;
}

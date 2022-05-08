#include <bits/stdc++.h>
using namespace std;

/***************  3.1.5, 05  ***************/
#define maxsize 5
typedef struct {
  int stack[maxsize];
  int top1;
  int top2;
} stk;

// 栈的初始化
void initStack(stk &s) {
  s.top1 = -1;
  s.top2 = maxsize;
}

// 判断栈空
bool isEmpty(stk &s, int num) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (num == 1) return s.top1 == -1;
  return s.top2 == maxsize;
}

// 判断栈满
bool isFull(stk &s) {
  if (s.top2 - s.top1 == 1) return true;
  return false;
}

// 入栈
bool push(stk &s, int num, int x) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (isFull(s)) {
    cout << "栈满" << endl;
    return false;
  }

  if (num == 1) s.stack[++s.top1] = x;
  else s.stack[--s.top2] = x;
  return true;
}

// 出栈
bool pop(stk &s, int num, int &x) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (isEmpty(s, num)) {
    cout << "栈空" << endl;
    return false;
  }

  if (num == 1) x = s.stack[s.top1--];
  else x = s.stack[s.top2++];
  return true;
}
/************  22/05/04 Mancuoj  ***********/

int main() {
  stk s;
  initStack(s);

  int x;
  pop(s, 1, x);       // 栈空
  push(s, 1, 10);
  push(s, 1, 11);
  push(s, 1, 12);
  push(s, 2, 49);
  push(s, 2, 50);
  push(s, 2, 51);     // 栈满
  pop(s, 1, x);       // 12
  pop(s, 1, x);       // 11
  cout << x << endl;
  pop(s, 2, x);       // 50
  cout << x << endl;

  return 0;
}

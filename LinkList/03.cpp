#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode* next;
}LNode, *LinkList; 

// 创建一个带头结点的单链表
LinkList createHeadList(vector<int> data) {
  if (data.size() == 0) return NULL;

  LNode* head = (LinkList)malloc(sizeof(LNode));
  head->next = NULL;

  LNode* p = head;
  for (int i = 0; i < data.size(); i++) {
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->data = data[i];
    q->next = NULL;
    p->next = q;
    p = q;
  }
  return head;
}

void printList(LinkList L) {
  while (L != NULL) {
    cout << L->data << " ";
    L = L->next;
  }
  puts("");
}

/***************  2.3.7, 03  ***************/
void reversePrintList(LinkList L) {
  if (L == NULL) return;
  reversePrintList(L->next);
  cout << L->data << " ";
}

void reversePrintList2(LinkList L) {
  if (L == NULL) return;

  stack<int> stack;
  while (L != NULL) {
    stack.push(L->data);
    L = L->next;
  }
  while (!stack.empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }
}
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head->next);

  // reversePrintList(head->next);
  reversePrintList2(head->next);
  puts("");

  cout << "修改后: ";
  printList(head->next);
  return 0;  
}

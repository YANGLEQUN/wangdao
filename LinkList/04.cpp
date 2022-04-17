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
  while (L->next != NULL) {
    cout << L->next->data << " ";
    L = L->next;
  }
  puts("");
}

/***************  2.3.7, 04  ***************/
void delMin(LinkList &L) {
  // 1.定义指针
  LNode *pre = L, *p = pre->next;
  LNode *minpre = pre, *minp = p;

  // 2.找到最小值
  while (p != NULL) {
    if (p->data < minp->data) {
      minpre = pre;
      minp = p;
    }
    pre = p;
    p = p->next;
  }

  // 3.删除最小值
  minpre->next = minp->next;
  free(minp);
}
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  delMin(head);

  cout << "修改后: ";
  printList(head);
  return 0;  
}
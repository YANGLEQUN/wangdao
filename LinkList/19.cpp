#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode* next;
}LNode, *LinkList; 

// 创建一个带头结点的循环单链表
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

  p->next = head;  // 最后指向头指针
  return head;
}

void printList(LinkList L) {
  if (L->next == NULL) return;

  LNode *head = L->next;
  while (head != L) {
    cout << head->data << " ";
    head = head->next;
  }
  puts("");
}

/***************  2.3.7, 19  ***************/
void delMin(LinkList L) {
  // 1.只剩一个头结点时停止
  while (L->next != L) {
    LNode *minpre = L, *p = L->next;
    
    // 2.找到最小值，记录其前缀
    while (p->next != L) {
      if (p->next->data < minpre->next->data)
        minpre = p;
      p = p->next;
    }
    
    // 3.输出并释放最小值结点
    cout << minpre->next->data << ' ';
    LNode *del = minpre->next;
    minpre->next = del->next;
    free(del);
  }

  // 4.释放头结点
  free(L);
}

int getLength(LinkList L) {
  int i = 0;
  LNode *p = L->next;
  while (p != L) {
    p = p->next;
    i++;
  }
  return i;
}

void delMin2(LinkList L) {
  int len = getLength(L);
  int a[len], i = 0;

  LNode *head = L->next;
  while (head != L) {
    a[i++] = head->data;
    head = head->next;
  }

  sort(a, a+len);

  for (int i = 0; i < len; i++)
    cout << a[i] << ' ';
  puts("");

  // 释放所有结点空间，此处省略
}
/************  22/04/20 Mancuoj  ***********/

int main() {
  vector<int> data{6, 7, 3, 4, 2, 9, 1, 8, 5, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  // delMin(head);
  delMin2(head);
  return 0;  
}

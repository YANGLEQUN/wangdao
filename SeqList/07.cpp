#include <bits/stdc++.h>
#define MaxSize 50

using namespace std;

typedef struct {
  int data[MaxSize];
  int length;
}SqList; 

// 打印数组
void print_list(SqList &list) {
  for (int i = 0; i < list.length; i++)
    cout << list.data[i] << ' ';
  cout << endl;
}

SqList init_list(int len, int d) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) 
    list.data[i] = i + d;

  return list;
}

/***************  2.2.3, 07  ***************/
SqList merge(SqList A, SqList B) {
  SqList C;
  if (A.length + B.length > MaxSize) {
    cout << "ERROR!" << endl;
    return C;
  }

  int i = 0, j = 0, k = 0;
  // 1.两两比较，小的存入结果表
  while (i < A.length && j < B.length) {
    if (A.data[i] <= B.data[j])
      C.data[k++] = A.data[i++];
    else
      C.data[k++] = B.data[j++];
  }

  // 2.剩下的全部加入结果表，两个循环只会有一个运行
  while (i < A.length) 
    C.data[k++] = A.data[i++];
  while (i < B.length) 
    C.data[k++] = B.data[j++];

  // 3.返回结果表
  C.length = k;
  return C;
}
/***************  2.2.3, 07  ***************/

int main() {
  SqList list1 = init_list(10, 5);
  SqList list2 = init_list(8, 4);

  cout << "原数组1: ";
  print_list(list1);
  cout << "原数组2: ";
  print_list(list2);

  SqList list = merge(list1, list2);

  cout << "合并后: ";
  print_list(list);
  return 0;  
}

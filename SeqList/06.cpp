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

// 插入
void insert_list(SqList &list, int idx, int e) {
  
}

// 生成一个有序重复列表, [0, len-1]
SqList init_list(int len) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) 
    list.data[i] = i;

  return list;
}

/***************  2.2.3, 06  ***************/
void del_same(SqList &list) {
  
}
/***************  2.2.3, 06  ***************/

int main() {
  SqList list = init_list(10);

  cout << "原数组: ";
  print_list(list);

  del_same(list);

  cout << "修改后: ";
  print_list(list);
  return 0;  
}

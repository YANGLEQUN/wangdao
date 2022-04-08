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

// 生成一个无序不重复列表, [0, len-1]
SqList init_list(int len) {
  srand(time(NULL));
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) 
    list.data[i] = i;

  for (int i = len - 1; i >= 0; i--) 
    swap(list.data[i], list.data[rand() % len]);

  return list;
}

/***************  2.2.3, 05  ***************/
void del_st(SqList &list, int s, int t) {
  if (s >= t || list.length == 0) {
    cout << "ERROR!" << endl;
    return;
  }

  // 1.要保存的值都放在前面
  int k = 0; 
  for (int i = 0; i < list.length; i++) {
    if (list.data[i] < s || list.data[i] > t) {
      list.data[k++] = list.data[i];
    }
  }
  
  // 2.直接扔掉后面的值
  list.length = k;
}
/************  22/04/08 Mancuoj  ***********/

int main() {
  SqList list = init_list(10);
  cout << "原数组: ";
  print_list(list);

  // del_st(list, 0, 3);
  del_st(list, 2, 6);

  cout << "修改后: ";
  print_list(list);
  return 0;  
}

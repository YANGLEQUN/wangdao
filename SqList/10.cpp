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

SqList init_list(int len) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) 
    list.data[i] = i;

  return list;
}

/***************  2.2.3, 10  ***************/
void change(SqList &list, int p, int n) {
  // 左右两个数组分别是[0, p-1], [p, n-1]
  SqList copied = list;
  int k = -1;
  for (int i = p; i < n; i++) {
    copied.data[++k] = list.data[i];
  }
  for (int i = 0; i < p; i++) {
    copied.data[++k] = list.data[i];
  }
  list = copied;
}

void reverse(SqList &list, int l, int r) {
  if (l > r || r > list.length) return;

  for (int i = 0; i < (r-l+1)/2 ; i++) {
    swap(list.data[l+i], list.data[r-i]);
  }
}

// 方法二，整体逆置，再分别逆置
void change2(SqList &list, int p, int n) {
  // 注意参数
  reverse(list, 0, n);
  reverse(list, 0, p);
  reverse(list, p, n);
}
/************  22/04/11 Mancuoj  ***********/

int main() {
  SqList list = init_list(10);
  cout << "原数组: ";
  print_list(list);

  // change(list, 5, list.length);
  // change2(list, 5, list.length);
  change2(list, 3, list.length);

  cout << "修改后: ";
  print_list(list);
  return 0;  
}
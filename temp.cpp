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

// 生成一个无序列表, [0, len-1]
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





int main() {
  SqList list = init_list(10);
  cout << "原数组: ";
  print_list(list);



  cout << "修改后: ";
  print_list(list);
  return 0;  
}

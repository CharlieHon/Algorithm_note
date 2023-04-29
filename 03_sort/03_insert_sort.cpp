#include <iostream>
using std::cout; using std::cin; using std::endl;

// 插入排序
void insertSort(int a[], const int n){
    for(int i=1; i<n; ++i){
        int temp = a[i], j = i; // temp存放待插入元素，j从i开始往前枚举
        while(j>0 && temp<a[j-1]){  // 只要temp小于前一个元素a[j-1]
            a[j] = a[j-1];  // 把a[j-1]后移一位至a[j]
            --j;
        }
        a[j] = temp;    // 插入位置为j
    }
}

// 打印数组
void printArray(int a[], const int n){
    for(int i=0; i<n; ++i){
        cout << a[i];
        if(i==n-1)  cout << endl;
        else    cout << " ";
    }
}

int main()
{
    int a[] = {1,8,9,5,2,0,2,3};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "origin:" << endl;
    printArray(a, n);
    insertSort(a, n);
    cout << "sorted:" << endl;
    printArray(a, n);

    return 0;
}
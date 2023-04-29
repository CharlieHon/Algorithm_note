#include <iostream>
using std::cout; using std::cin; using std::endl;

// 选择排序
void selectSort(int a[], const int n){
    for(int i=0; i<n-1; ++i){ // 进行n-1趟操作
        int flag = i;   // [0,i-1] 为已排序部分
        for(int j=i+1; j<n; ++j){   // 从 [i+1,n-1] 中选出比a[i]小的与其交换
            if(a[j] < a[flag])      // 使得 [0,i] 已排序
                flag = j;
        }
        int temp = a[i];
        a[i] = a[flag];
        a[flag] = temp;
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
    int a[] = {1,8,9,5,2,0,2,3,7,4};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "origin:" << endl;
    printArray(a, n);
    selectSort(a, n);
    cout << "sorted:" << endl;
    printArray(a, n);

    return 0;
}
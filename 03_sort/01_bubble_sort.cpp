#include <iostream>
using std::cout; using std::cin; using std::endl;

// 冒泡排序
void bubbleSort(int a[], const int n){
    for(int i=0; i<n-1; ++i){   // 进行n-1次冒泡，每次找到未排序部分的最大值
        for(int j=0; j<n-1-i; ++j){ // 第i次冒泡，需要进行n-1-i次比较(i从0开始)
            if(a[j] > a[j+1]){  // 交换
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    bubbleSort(a, n);
    cout << "sorted:" << endl;
    printArray(a, n);

    return 0;
}
#include <cstdio>
#include <algorithm>
// 1.如何使用sort排序
// 使用sort排序，必须加上头文件 #include<algorithm>
using namespace std;
int main()
{
    // 和 using namespace std;  使用的方式如下：
    // sort(首元素地址, 尾元素地址的下一个地址, 比较函数(选填));    默认升序排序
    int a[] = {2,0,2,3,0,4,2,9,9};
    int n = sizeof(a)/sizeof(a[0]);
    // sort(a, a+4);   // 对 a[0]~a[3] 进行排序
    sort(a, a+n);   // 对整个数组进行从小到大排序
    for(auto x : a){
        printf("%d ", x);
    }
    printf("\n");

    // 对double型数组排序
    double b[] = {0.1412,3.1415,0.6667,4.29};
    int n2 = sizeof(b)/sizeof(b[0]);
    sort(b, b+n2);
    for(auto x : b){
        printf("%.4f ", x); // 0.1412 0.6667 3.1415 4.2900 
    }
    printf("\n");

    // 对char型数组排序
    char c[] = {'c','h','a','r','l','i','e'};
    int n3 = sizeof(c)/sizeof(c[0]);
    sort(c, c+n3);
    for(auto x : c){
        printf("%c ", x);   // a c e h i l r
    }
    printf("\n");

    return 0;
}
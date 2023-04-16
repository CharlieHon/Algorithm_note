#include <cstdio>
/*
* 题目：找x
* 输入格式：
* 输出格式：
*/
const int N = 210;
int a[N] = {0};

int main()
{
    int n, x;   // n个数，x是要查询的数
    while(scanf("%d", &n) != EOF){  // 连续运行该功能，直到输入Ctrl+Z回车结束
        for(int i=0; i<n; ++i){
            scanf("%d", &a[i]);
        }
        scanf("%d", &x);
        int i;  // 下标
        for(i=0; i<n; ++i){
            if(a[i] == x)   break;  // 如果找到了x，退出循环
        }
        if(i == n)  printf("-1\n"); // 没找到x
        else    printf("%d\n", i);
    }

    return 0;
}
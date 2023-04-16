#include <cstdio>
#include <cmath>
/*
* 题目：跟奥巴马一起编程
* 输入格式：
* 输出格式：
*/
int main()
{
    int n;  // 边长
    char c; // 字符
    scanf("%d %c", &n, &c);
    // int row = round(double(n)/2);   // round四舍五入
    int row = (n & 1) ? (n+1)/2 : n/2;
    for(int i=0; i<row; ++i){
        for(int j=0; j<n; ++j){
            if(i==0 || i==(row-1))  // 第1行和最后一行全部输出字符
                printf("%c", c);
            else{   // 其余行
                if(j==0 || j==(n-1))    printf("%c", c);    // 第1个和最后一个字符输出字符
                else    printf(" ");    // 其他输出为空格
            }
            if(j == n-1)    printf("\n");
        }
    }

    return 0;
}
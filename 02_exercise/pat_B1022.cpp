#include <iostream>
/**
 * @brief 输入两个非负十进制整数A和B(≤2^30-1)以及D(进制数)，输出A+B的D(1＜D≤10)进制数
 * 输入样例：
 * 123 456 8
 * 输出样例：
 * 1103
 * @return int 
 */
int main()
{
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int c = a+b, res[40], num = 0;  // 数组res存放A+B的D进制每位数
    do{
        res[num++] = c % d;
        c /= d;
    }while(c != 0);
    for(int i=num-1; i>=0; --i){    // 从高位到低位进行输出
        printf("%d", res[i]);
    }

    return 0;
}
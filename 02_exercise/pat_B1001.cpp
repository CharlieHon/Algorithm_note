#include <cstdio>
/*
* 题目：卡拉兹(Callatz)猜想：对于任何一个自然数n，如果它是偶数，那么把它砍掉一般；如果是奇数，那么把(3n+1)砍掉一半。一直反复下去直到得到n=1。
* 输入格式：给出自然数n的值
* 输出格式：输出从n到1需要的步数
*/
int main()
{
    int n, step = 0;
    scanf("%d", &n);
    while(n != 1){
        if(n & 1)   n = (3*n+1)/2;
        else    n /= 2;
        ++step;
    }
    printf("%d\n", step);

    return 0;
}
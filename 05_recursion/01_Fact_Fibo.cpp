#include <cstdio>

// 求阶乘
int Fact(int n){
    if(n==0)
        return 1;
    return n*Fact(n-1);
}

// 求斐波那契序列
int Fibo(int n){
    if(n==0 || n==1)
        return 1;
    return Fibo(n-1)+Fibo(n-2);
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("Factorial(x) = %d\nFibonacci(x) = %d\n", Fact(x), Fibo(x));

    return 0;
}
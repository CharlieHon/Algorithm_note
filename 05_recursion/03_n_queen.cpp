#include <cstdio>
#include <cmath>
/**
 * @brief n皇后问题：在一个n*n的国际象棋棋盘上放置n个皇后，使得这n个皇后两两均不在同一行、同一列、同一对角线上，求合法的方案数。
 */
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;  // 合法的方案数

void nQueen(int index){
    if(index==n+1){ // 同全排列，递归边界
        bool flag = true;
        for(int i=1; i<n; ++i){ // 当由两个皇后在同一对角线上时，方案非法
            for(int j=i+1; j<=n; ++j){
                if(abs(P[i]-P[j])==abs(i-j)){
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        if(flag)    ++count;    // 方案合法则计数加1
        return;
    }
    for(int x=1; x<=n; ++x){    // 同全排列
        if(!hashTable[x]){
            P[index] = x;
            hashTable[x] = true;
            nQueen(index+1);
            hashTable[x] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    nQueen(1);
    printf("%d-Queen: %d\n", n, count);

    return 0;
}
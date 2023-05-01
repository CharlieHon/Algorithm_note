#include <cstdio>
#include <cmath>
/**
 * @brief 对n皇后问题进行优化
 * 
 */
const int maxn = 12;
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;

void nQueen(int index){
    if(index==n+1){
        ++count;    // 前已判断合法性，达到递归边界即进行计数加1
        for(int i=1; i<=n; ++i){
            printf("%d", P[i]);
        }
        printf("\n");
    }

    for(int x=1; x<=n; ++x){
        bool flag = true;   // 合法性标记
        if(!hashTable[x]){  // 如果x未出现在P[1]~P[index-1]中
            for(int i=1; i<=index-1; ++i){  // 1~index-1为合法的已排列部分
                if(abs(i-index)==abs(P[i]-x)){  // 当 P[index]=x 引起有两个皇后位于同一对角线时，
                    flag = false;   // 方案非法
                    break;
                }
            }
            if(!flag)   continue;   // 如果方案非法，则对 下一个x进行判断
            P[index] = x;   // 以下部分同全排列
            hashTable[x] =true;
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
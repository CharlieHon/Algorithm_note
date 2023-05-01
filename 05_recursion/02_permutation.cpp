#include <cstdio>
const int maxn = 11;
// P为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = {false};

// 当前处理排列的第index位
void generateP(int index){
    if(index==n+1){ // index=n+1为递归边界
        for(int i=1; i<=n; ++i){    // 打印输出全排列
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    // 对1~n全排列，x遍历整数1~n
    for(int x=1; x<=n; ++x){
        if(!hashTable[x]){  // 如果x还没出现在P[1]~P[index-1]
            P[index] = x;   // 则令P[index]=x，因为x是按顺序1~m顺序遍历，所以输出也符合字典序从小到大顺序
            hashTable[x] = true;    // 将x标记为已出现
            generateP(index+1); // 递归处理下一位
            hashTable[x] = false;   // index处以x开头的全排列已全部枚举，将hashTable[x]置零后继续开始以x+1开头的全排列
        }
    }
}

int main()
{
    while(scanf("%d", &n)!=EOF){    // 持续输出全排列n，直到EOF
        generateP(1);
    }

    return 0;
}
#include <cstdio>
/*
* 题目：挖掘机技术哪家强
* 输入格式：
* 输出格式：
*/

const int N = 1e5 + 10;
int a[N];   // 记录每个学校的总分，初始值为0

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int num, score;
        scanf("%d %d", &num, &score);
        a[num] += score;
    }
    int maxScore = -1, maxNum = 1;
    for(int i=1; i<=n; ++i){
        if(a[i] > maxScore){
            maxScore = a[i];
            maxNum = i;
        }
    }
    printf("%d %d\n", maxNum, maxScore);

    return 0;
}
#include <cstdio>
/**
 * @brief 给出N个正整数，再给出M个正整数，问这M个数中的每个数分别是否在N个数中出现过
 */
const int maxn = 100010;
bool hashTable[maxn] = {false};
int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i){
        scanf("%d", &x);
        hashTable[x] = true;
    }
    for(int i=0; i<m; ++i){
        scanf("%d", &x);
        if(hashTable[x])    printf("YES\n");
        else    printf("NO\n");
    }

    return 0;
}
#include <cstdio>
#include <cstring>
/**
 * @brief 字符串hash：将一个字符串S映射为一个整数，使得该整数可以尽可能唯一地代表字符S。
 */

// 先假设字符串均由大写字母A~Z构成。在这个基础上，不妨把A~Z视为0~25，这样就把26个大写字母对应到了二十六进制中。接着，按照将二十六进制转换为十进制地思路……
// 转换成的整数最大为 26^len-1 其中len为字符串长度。
int hashFunc1(char S[], int len){   // hash函数，将字符串S转换为整数
    int id = 0;
    for(int i=0; i<len; ++i){
        id = id*26 + (S[i]-'A');    // 将二十六进制转换为十进制
    }
    return id;
}

// 如果字符串中出现了小写字母，那么可以把A~Z作为0~25，而把a~z作为26~51
int hashFunc2(char S[], int len){
    int id = 0;
    for(int i=0; i<len; ++i){
        if(S[i]>='A' && S[i]<='Z')
            id = id*52 + (S[i]-'A');
        else if(S[i]>='a' && S[i]<='z')
            id = id*52 + (S[i]-'a') + 26;
    }
    return id;
}

// 如果出现了数字，一般有两种处理方法
// 1. 按照小写字母的处理方法，增大进制至62
// 2.如果保证在字符串的末尾的是确定个数的数字，那么就可以把前面英文字母的部分按上面的思路转换成整数，再将末尾的数字直接拼接上去
int hashFunc3(char S[], int len){   // 以末尾有一个字母为例，前面全为大写字母
    int id = 0;
    for(int i=0; i<len-1; ++i){
        id = id*26 + (S[i]-'A');
    }
    id = id*10 + (S[len-1]-'0');    // 最后一位为数字0~9
    return id;
}

/**
 * @brief 给出N个字符串（由签好三位大写字母组成），再给出M个查询字符串，问每个查询字符串在N个字符串出现的次数
 */
const int maxn = 10010;
int hashTable[maxn] = {0};
int hashFunc(char S[], int len){
    int id = 0;
    for(int i=0; i<len-1; ++i){
        id = id*26 + (S[i]-'A');
    }
    id = id*10 + (S[len-1]-'0');
    return id;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char s[5];
    for(int i=0; i<n; ++i){
        scanf("%s", s);
        ++hashTable[hashFunc(s, 4)];
    }
    for(int i=0; i<m; ++i){
        scanf("%s", s);
        printf("%d\n", hashTable[hashFunc(s, 4)]);
    }

    return 0;
}
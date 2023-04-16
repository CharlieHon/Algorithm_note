#include <cstdio>
#include <cstring>

int main()
{
    char str[90];
    gets(str);  // 未知原因报错，但是可以编译运行
    int sz = strlen(str), row = 0, col = 0;
    printf("strlen is %d\n", sz);
    char res[90][90];   // 结果数组，每行为一个单词
    for(int i=0; i<sz; ++i){
        if(str[i] != ' '){  // 如果不是空格
            res[row][col++] = str[i];   // 填入单词中
        }else{
            res[row][col] = '\0';   // 是空格填入空字符，表示C风格字符串的结束
            ++row;  // 行数加1
            col = 0;    // 列数重新置零
        }
    }
    for(int i=row; i>=0; --i){  // 从row开始是因为strlen长度不包括C风格字符串最后一个空字符。因此到最后一个单词时，没有执行else语句，所以row就等于实际单词数-1！
        printf("%s", res[i]);   // 倒着输出
        if(i != 0)  printf(" ");
    }
    return 0;
}
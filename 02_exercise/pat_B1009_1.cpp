#include <cstdio>
#include <cstring>
char a[88][88];

int main()
{
    int num = 0;    // num为单词个数
    while(scanf("%s", a[num]) != EOF){  // 一直输入直到文件末尾(Ctrl+Z+Enter)
        ++num;
    }
    for(int i=num-1; i>=0; --i){    // 倒着输出单词
        printf("%s", a[i]);
        if(i != 0)  printf(" ");
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> vs;
    string word;
    while(cin >> word){
        vs.push_back(word);
    }
    for(auto last=vs.end()-1; last>=vs.begin(); --last){
        cout << *last << " ";
    }
    cout << endl;

    return 0;
}
*/
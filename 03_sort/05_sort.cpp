#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 2.如何实现比较函数cmp
// 对结构体类型、STL容器进行自定义规则排序时cmp的写法
using namespace std;

struct node{
    int x, y;
}ssd[10];

// 内置类型排序，不同内置类型仅改变函数的参数类型即可
bool cmp1(int a, int b){
    return a>b; // 可以理解为当a>b时把a放在b前面，即从大到小排序
}

// 结构体数组的排序
bool cmp2(node a, node b){
    // 如何a.x!=b.x，按照x从大到小排序，否则按照y从小打大排序
    return (a.x!=a.y) ? (a.x>b.x) : (a.y<b.y);
}

// 根据字符串长度进行排序
bool cmp3(const string &a, const string &b){
    // 按照字符串长度从大到小排序
    return a.size() > b.size();
}

int main()
{
    // 1.内置类型
    int a[] = {1,8,9,5,2,0,2,3};
    int n1 = sizeof(a)/sizeof(a[0]);
    sort(a, a+n1, cmp1);
    for(auto x : a){
        printf("%d ", x);   // 9 8 5 3 2 2 1 0
    }
    printf("\n");

    // 2.结构体
    ssd[0].x = 2;   // {2,2}
    ssd[0].y = 2;
    ssd[1].x = 1;   // {1,3}
    ssd[1].y = 3;
    ssd[2].x = 3;   // {3,1}
    ssd[2].y = 1;
    ssd[3].x = 3;
    ssd[3].y = 2;

    sort(ssd, ssd+4, cmp2);
    for(const auto &elem : ssd){
        printf("%d %d\n", elem.x, elem.y);
    }

    // 3.容器的排序-vector
    vector<int> vi{7,5,6,9,2,1,3,12};
    // 比较函数选取容器中元素同类型的比较函数即可，如下为整型按照从大到小排序函数cmp1
    sort(vi.begin(), vi.end(), cmp1);   // 使用迭代器表示容器范围
    for(int x : vi){
        printf("%d ", x);   // 12 9 7 6 5 3 2 1 
    }
    printf("\n");

    // 容器的排序-string
    string s[] = {"alpha","gamma","delta","beta"};
    // 将string型数组按字典序从小到大输出
    sort(begin(s), end(s));
    for(auto w : s){
        cout << w << endl;  // alpha beta delta gamma
    }

    string s2[] = {"hello","hi","good","life"};
    sort(begin(s2), end(s2), cmp3); // 按照字符串长度从大到小排序
    for(const auto &w : s2){
        cout << w << endl;
    }

    return 0;
}
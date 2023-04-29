#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 1.定义学生结构以
struct Student{
    char name[10];  // 姓名
    char id[10];    // 准考证号
    int score;  // 分数
    int r;  // 排名
}stu[100010];

// 2.cmp函数
bool cmp(const Student &s1, const Student &s2){
    // 如果两个学生分数不同，则分数高的排在前面
    // 否则，将姓名字典序小的排在前面
    return (s1.score!=s2.score) ? (s1.score>s2.score) : (strcmp(s1.name,s2.name)<0);
}

// 3.排名的实现
// 分数不同的排名不同，分数相同的排名相同但占用一个排位
// 对这种要求，一般都需要在结构体类型定义时把排名这一项加到结构体中
// 先将数组第一个个体的排名记为1，然后遍历剩余个体：如果当前分数与上一个相同，那么排名相同；否则，当前个体排名等于数组下标加1
/*
stu[0].r = 1;
for(int i=1; i<n; ++i){
    if(stu[i].score==stu[i-1].score)
        stu[i].r = stu[i-1].r;
    else
        stu[i].r = i+1;
}
*/

// 或者直接输出排名
/*
int r = 1;
for(int i=0; i<n; ++i){
    if(i>0 && stu[i].score!=stu[i-1].score)
        r = i+1;
    printf("rank: %d\n", r);
}
*/

int main()
{
    
    return 0;
}
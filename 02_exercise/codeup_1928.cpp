#include <iostream>
using std::swap;
/*
* 题目：日期差值有两个日期，求两个日期之间的天数，如果两个日期是连续的，则规定它们之间的天数为两天
* 输入格式：有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD。
* 输出格式：每组数据输出一行，即日期差值
* 样例输入：
    20130101
    20130105
* 样例输出：
    5
*/
bool isLeap(int year){  // 判断是否是闰年
    if((year%400==0) || (year%4==0 && year%100!=0)) // 是400的倍数  或者  是4的倍数但不是100的倍数
        return true;
    return false;
}
int month[13][2] = {    // 平年闰年月份天数
    {0, 0},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};

int main()
{
    int y1,m1,d1,y2,m2,d2,date1,date2;
    while(scanf("%d%d", &date1, &date2) != EOF){
        if(date1 > date2)   swap(date1, date2); // 保证data1 < date1，如下从date1日期开始计数到data2
        y1 = date1/10000; m1 = date1%10000/100, d1 = date1%100;
        y2 = date2/10000; m2 = date2%10000/100, d2 = date2%100;
        int res = 1;    // 记录结果
        while(y1!=y2 || m1!=m2 || d1!=d2){  // 或都改为 <
            ++res;
            ++d1;
            if(d1 > month[m1][isLeap(y1)]){
                d1 = 1;
                ++m1;
                if(m1 > 12){
                    ++y1;
                    m1 = 1;
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
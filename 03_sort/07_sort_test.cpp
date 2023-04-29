#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Stu{
    char id[15];    // registration
    int final_rank; // final_rank
    int loc_num;    // location_num
    int loc_rank;   // local_rank
    int score;      // score
}stu[30010];

bool cmp(const Stu &s1, const Stu &s2){
    // 分数不同，按分数从大到小排序；否则，按照字典序从小到大排序
    return (s1.score!=s2.score)?(s1.score>s2.score):(strcmp(s1.id,s2.id)<0);
}

int main()
{
    int N, K, total = 0;    // N个考场，每个考场K名学生，总共total个学生
    scanf("%d", &N);
    for(int i=0; i<N; ++i){ // 第i个考场
        scanf("%d", &K);    // 该考场学生数
        for(int j=0; j<K; ++j){
            scanf("%s %d", &stu[total+j].id, &stu[total+j].score);
            stu[total+j].loc_num = i+1; // 
        }
        sort(stu+total, stu+total+K, cmp);  // 排序
        stu[total].loc_rank = 1;    // 局部考场排名
        for(int k=total+1; k<total+K; ++k){
            if(stu[k].score==stu[k-1].score)    stu[k].loc_rank = stu[k-1].loc_rank;
            else    stu[k].loc_rank = k+1-total;
        }
        total += K; // 总数增加
    }
    sort(stu, stu+total, cmp);
    stu[0].final_rank = 1;
    printf("%d\n", total);
    printf("%s %d %d %d\n", stu[0].id, stu[0].final_rank, stu[0].loc_num, stu[0].loc_rank);
    for(int i=1; i<total; ++i){ // 总考场排名
        if(stu[i].score==stu[i-1].score)    stu[i].final_rank = stu[i-1].final_rank;
        else    stu[i].final_rank = i+1;
        printf("%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].loc_num, stu[i].loc_rank);
    }

    return 0;
}
#include <iostream>
/**
 * @brief 进制转换
 * 
 * @return int 
 */
int main()
{
    // 进制转换
    // 1.将P进制数x转换为十进制数y
    int x, P;
    int y, product = 1; // product是P进制某位上的权重1 = P^0
    scanf("%d %d", &P, &x);
    int x1(x);  // 保留原始数据
    while(x1 != 0){
        y = y + (x1 % 10)*product;   // 取最小位上数乘以权重(p^product)
        x1 /= 10;    // 去掉最小位
        product *= P;   // 从最小到最大位上权重
    }

    printf("%d-scale %d to dec is %d\n", P, x, y);  // P进制数x转换为十进制y为

    // 将十进制y转换为Q进制
    int y1(y);  // 保留数据
    int z[40], Q = 8, num = 0;  // num为位数，Q是进制，数组z存放Q进制y的每一位
    do{
        z[num++] = y % Q;   // 除基取余，数组z从高位z[num-1]到低位z[0]即为Q进制z
        y /= 10;
    }while(y != 0);
    int Z = 0; product = 1;
    for(int i=0; i<num; ++i){
        Z = Z + z[i] * product;
        product *= 10;
    }
    printf("%d-scale %d to %d-scale is %d\n", 10, y1, Q, Z);

    return 0;
}

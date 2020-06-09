//예제 6-1
#include <stdio.h>

#pragma warning(disable : 4996)

void main()
{
    int n, count;
    float avg, d, sum = 0;
    float list[100];
    printf("평균을 내고자 하는 데이터의 개수는? ");
    scanf("%d", &n);
    for (count = 0; count < n; ++count)
    {
        printf("i = %d x =", count + 1);
        scanf("%f", &list[count]);
        sum += list[count];
    }
    avg = sum / n;
    printf("The averge is %5.2f \n", avg);
    for (count = 0; count < n; ++count)
    {
        d = list[count] - avg;
        printf("i = %d x = %5.2f d=%5.2f \n", count + 1, list[count], d);
    }
}

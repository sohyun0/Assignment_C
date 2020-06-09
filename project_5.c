#include <stdio.h>

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *even = x;
    int *odd = &x[1];
    int even_sum = 0;
    int odd_sum = 0;
    for (int i = 0; i < 5; i++)
    {
        even_sum += *even;
        odd_sum += *odd;
        even += 2;
        odd += 2;
    }
    printf("짝수 번 요소의 합 : %d \n", even_sum);
    printf("홀수 번 요소의 합 : %d \n", odd_sum);
}
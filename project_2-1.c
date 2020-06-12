//예제 5-1
#include <stdio.h>              //파일포함 선행처리기
#pragma warning(disable : 4996) // 권장되지 않은 함수사용에 대한 경고 제외
char upper(char ch);            // 문자형으로 변수 upper를 선언
char lower(char ch);            //문자형으로 변수 lower를 선언
void main()                     // main() 함수 시작
{
    char in_s[50], out_s[50];                      //배열 크기가 50인 문자형 배열 in_s[50], out_s[50] 선언
    char ch;                                       // 문자형 변수 ch 선언
    int i = 0;                                     // 정수형 변수 i 선언과 동시에 0으로 초기화
    printf("문자열을 입력하시오. (50자 이내) : "); //사용자로 부터 입력을 요구하는 문장을 출력
    scanf("%s", in_s);                             //문자형 배열 in_s[50]에 50자 이내의 문자열을 사용자로 부터 입력받음
    ch = in_s[i];                                  // ch변수에 사용자가 입력한 문자열을 i에 대입함.
    while (ch != '\0')                             // 변수 ch에 null문자가 올때까지 반복한다
    {
        if (ch >= 'A' && ch <= 'Z') // 만약 변수ch안에 있는 값이 대문자 A에서 Z 사이에 있는경우
        {
            out_s[i] = lower(ch); //out_s[i]에 lower함수를 이용하여 문자를 소문자로 변환하여 대입
        }
        else if (ch >= 'a' && ch <= 'z') // 변수ch안에 있는 값이 대문자가 아닌 소문자 a에서 z사이에 있는경우
        {
            out_s[i] = upper(ch); //out_s[i]에 upper함수를 이용하여 문자를 대문자로 변환하여 대입
        }
        else // 대문자나 소문자가 아닌 특수문자, 한글같은 문자일 경우
        {
            out_s[i] = ch; // out_s[i]를ch에 대입
        }
        i++;          // 다음 명령어를 실행하기 전에 i에 +1을 해준다
        ch = in_s[i]; //ch를 in_s[i]에 대입
    }
    out_s[i] = '\0';
    printf("변환된 결과 ==>  %s \n", out_s);
}
char upper(char ch)
{
    return ch - 32;
}
char lower(char ch)
{
    return ch + 32;
}
~
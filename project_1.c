#define _CRT_SECURE_NO_WARNINGS // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 3

//아래는 입력받을 학생의 구조체
typedef struct student
{
    char name[15];       //이름
    char department[30]; // 학과
    char rrn[14];        //13자리의 주민등록번호를 문자형 배열로 받음
    int birth = 0;
    int year, month, day;
    char gender[5];   // 성별
    char country[9];  // 국가
    char leafYear[9]; //윤년여부
} s;

int isStringDouble(char *s)
{
    size_t size = strlen(s);
    if (size == 
        return 0; // 0바이트 문자열은 숫자가 아님

    for (int i = 0; i < (int)size; i++)
    {
        if (s[i] == '.' || s[i] == '-' || s[i] == '+')
            continue;
        if (s[i] < '0' || s[i] > '9')
            return 0; // 알파벳 등이 있으면 숫자 아님
    }

    return 1; // 그밖의 경우는 숫자임
}

int main()
{
    char strtemp[14]{
        NULL,
    };
    int data, genderdata = 0, countrydata = 0; // 성별, 나라를 0과 1로 사용하기 위함
    int date_of_birth;                         // 생년월일 한꺼번에 입력받기

    s member[MAX];
    s *ptr[MAX];
    s *temp;

    for (int i = 0; i < MAX; i++)
    {
        ptr[i] = &member[i];
    }

    printf("%d명의 학생 정보를 입력하시오.\n", MAX);
    printf("---------------------------------\n");

    for (int i = 0; i < MAX; i++)
    { //이후 학생 수 추가하려면 MAX의 값만 바꿔주면 된다.
        int check;
        printf("이름 : ");
        scanf("%s", &member[i].name);
        printf("학과 : ");
        scanf("%s", &member[i].department);
    ENTER: //주민등록번호의 값이 이상하게 입력되었을 경우를 대비하여 goto문을 사용.
        printf("주민등록번호 : ");
        scanf("%s", &member[i].rrn);
        check = isStringDouble(strncpy(strtemp, member[i].rrn, 7)); // 주민등록번호 앞자리 6 + 뒷자리 1로 끊어서 문자열 확인
        if (check == 1)
        {                      //주민등록번호 문자열 체크시 전부 숫자일때 실행
            strtemp[6] = NULL; //7번째 배열부터 데이터가 필요하지 않으므로 처리
            strncpy(strtemp, member[i].rrn, 6);
            date_of_birth = atoi(strtemp);                   //문자열을 정수로 변환해주는 라이브러리
            member[i].year = date_of_birth / 10000;          //6자리 정수를 10000으로 나누어 앞의 2자리인 연도 구하기
            member[i].month = (date_of_birth % 10000) / 100; //위에서 10000으로 나눈 나머지 4자리수 년월일을 100으로 나눠서 월 구하기
            member[i].day = date_of_birth % 100;             // 100으로 나눈 나머지가 마지막 2자리 일자 구하기
            data = member[i].rrn[6];

            switch (member[i].month)
            { //주민등록번호의 월, 일 부분을 제대로 기입했는지 확인하기 위한 구문. 만약 문제가 없다면, 따로 표시되는 것은 없음.
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (member[i].day == 0 || member[i].day > 31)
                {
                    printf("올바른 주민등록번호를 입력하세요 \n");
                    goto ENTER;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (member[i].day == 0 || member[i].day > 30)
                {
                    printf("올바른 주민등록번호를 입력하세요 \n");
                    goto ENTER;
                }
                break;
            case 2: //윤년 확인하기
                if ((member[i].year % 4 == 0) && (member[i].year % 100 != 0) || (member[i].year % 400 == 0))
                {
                    if (member[i].day == 0 || member[i].day > 29)
                    {
                        printf("올바른 주민등록번호를 입력하세요 \n");
                        goto ENTER;
                    }
                }
                else
                {
                    if (member[i].day == 0 || member[i].day > 28)
                    {
                        printf("올바른 주민등록번호를 입력하세요 \n");
                        goto ENTER;
                    }
                }
                break;
            default:
                printf("올바른 주민등록번호를 입력하세요 \n");
                goto ENTER;
                break; //사실 다시 ENTER 부분으로 돌아가기 때문에 break는 없어도 되긴 하다...
            }

            switch (data)
            { //주민등록번호 7번째 수로 성별,국가 구분
            case '1':
                genderdata = 0;
                countrydata = 0;
                member[i].year += 1900;
                break;
            case '2':
                genderdata = 1;
                countrydata = 0;
                member[i].year += 1900;
                break;
            case '3':
                genderdata = 0;
                countrydata = 0;
                member[i].year += 2000;
                break;
            case '4':
                genderdata = 1;
                countrydata = 0;
                member[i].year += 2000;
                break;
            case '5':
                genderdata = 0;
                countrydata = 1;
                member[i].year += 1900;
                break;
            case '6':
                genderdata = 1;
                countrydata = 1;
                member[i].year += 1900;
                break;
            case '7':
                genderdata = 0;
                countrydata = 1;
                member[i].year += 2000;
                break;
            case '8':
                genderdata = 1;
                countrydata = 1;
                member[i].year += 2000;
                break;
            case '9':
                genderdata = 0;
                countrydata = 0;
                member[i].year += 1800;
                break;
            case '0':
                genderdata = 1;
                countrydata = 0;
                member[i].year += 1800;
                break;
            }

            if ((member[i].year % 4 == 0) && (member[i].year % 100 != 0) || (member[i].year % 400 == 0))
            {
                memcpy(member[i].leafYear, "윤년", 5);
            }
            else
            {
                memcpy(member[i].leafYear, "윤년아님", 9);
            }

            if (countrydata == 0)
            {
                memcpy(member[i].country, "대한민국", 9);
            }
            else
            {
                memcpy(member[i].country, "외국", 5);
            }

            if (genderdata == 0)
            {
                memcpy(member[i].gender, "남성", 5);
            }
            else
            {
                memcpy(member[i].gender, "여성", 5);
            }
            member[i].birth = (member[i].year * 10000) + (member[i].month * 100) + member[i].day;

            printf("%s, %d년 %02d월 %02d일, %s, %s, %s, %s \n", ptr[i]->name, ptr[i]->year, ptr[i]->month, ptr[i]->day, ptr[i]->leafYear, ptr[i]->country, ptr[i]->gender, ptr[i]->department);
        }
        else
        {
            printf("올바른 주민등록번호를 입력하세요 \n");
            goto ENTER;
        }
    }
    //오름차순으로 출력하기
    /*
    0~n번째 까지의 값을 0과1 1과2 2와 3으로 비교를한다
    n-1번째~n번째 까지의 값을 비교를 해서 최소 or 최대값찾기
    본인들끼리 비교하면 최소와 최대를 알수 없으므로 다른 변수를 호출하여
    여태까지 비교해본 값중에 가장큰것을 넣으면 최대  가장작은것을넣으면 최소
    여기서는 최대를 넣어 다음값이랑 비교 max보다 큰값을만나면 max에 큰값 넣는식으로 반복
    ==>최소 최대값 뽑기
    오름차순 : 최소~최대  일반 최소 최대값을 뽑아 두배열값의 위치를 바꿔야함 
    n번째 와n+1번째의 배열값을 서로비교
    n+1 번째의 값이 더 작을시에 서로값을 바꾸는데 그냥대입하면 한쪽값이 날아가기 때문에 temp같은
    임시변수를 설정해서 n+1값을 넣어둔후 n+1에 n값넣고 n에다 temp에 저장해둔 값을 집어넣는 식으로
    위치를 변경한다
    아래에 있는 오름차순은 구조체배열을 이용했으므로 구조체 
    0번, 1번, 2번 이런 식으로 같은 이름의 구조체의 배열 안에 
    각각의 학생 정보가 저장되어 있는 방식이라 구조체의 주소만 서로 바꿔주면 
    내부의 모든 값을 한번에 정렬할 수있기 떄문에 각각 학생의 생일 정보를 비교해서
    출력하기
    */
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (ptr[j]->birth > ptr[j + 1]->birth)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("=================================\n");
    printf("입력 받은 %d명의 정보를 생년월일 기준으로 오름차순으로 출력\n", MAX);
    printf("---------------------------------\n");

    for (int i = 0; i < MAX; i++)
    {
        printf("%s, %d년 %02d월 %02d일, %s, %s, %s, %s\n", ptr[i]->name, ptr[i]->year, ptr[i]->month, ptr[i]->day, ptr[i]->leafYear, ptr[i]->country, ptr[i]->gender, ptr[i]->department);
    }

    return 0;
}
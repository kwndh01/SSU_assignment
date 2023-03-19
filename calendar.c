#include <stdio.h>
#define standardYear  2023

int main()
{
    int year; //날짜를 입력받기 위한 변수
    int length; //기준날짜(2023)과 입력받은 날짜간의 차이 계산을 위한 변수
    int mods; //1월 시작 지점 계산을 위한 변수
    int array[42]; //날짜를 담을 array
    int i = 1; //array에 값을 입력하는 iteration
    int date = 1; //array에 입력될 0이 아닌 값
    int j = 1; //값을 출력할때 언제 단을 나눌지 계산하는 변수
    int month;
    /*1월 1일 시작지점 계산*/
    printf("************Calendar v1.0************");
    printf("Year: ");
    scanf("%d", &year);
    printf("Month: ");
    scanf("%d", &month);
    length = standardYear - year;
    mods = length % 7;
    if (mods != 0)
    {
        mods = 7 - mods;
    }
    /*mods값이 0이면 1월 1일이 일요일
     *mods값이 1이면 1월 1일이 월요일
     *mods값이 2이면 1월 1일이 화요일
     *mods값이 3이면 1월 1일이 수요일
     *mods값이 4이면 1월 1일이 목요일
     *mods값이 5이면 1월 1일이 금요일
     *mods값이 6이면 1월 1일이 토요일*/


    /*달력 출력 과정*/
    printf("\tJan/%d\n\n Sun Mon Tue Wed Thu Fri Sat\n", year);

    while (i <= 41)
    {
        if (i <= mods || date >= 32)
        {
            array[i] = 0; //1월 1일에 맞는 위치에 다다르기 전까지 혹은 31일이 초과한 경우 arr에 0등록
        }
        else
        {
            array[i] = date; // 1월 1일부터 31일까지 순서대로 arr에 등록
        }

        /*달력 출력*/
        if (i> mods && date< 32)
        {
            if(date< 10) //보기좋게 일의 자리 숫자는 공백을 추가로 더 넣어 출력
            {
                printf("   %d", array[i]); //일의 자리 숫자 구분
            }
            else
            {
                printf("  %d", array[i]); //십의 자리 숫자 구분
            }
            date ++; //다음날짜로 넘기기
        }
        else{
            printf("    "); // 존재하지 않는 날짜엔 공백을 입력
        }

        if (j==7) //단나누기
        {
            printf("\n");
            j = 0;
        }
        i++;
        j++;
    }
    return 0;
}
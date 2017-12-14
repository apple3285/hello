#include <stdio.h>
#include <stdlib.h> //srand함수와 rand 함수 포함 파일
#include <string.h> //strlen함수 포함 파일
#include <memory.h>
#include <time.h>//time 함수 포함 파일



void gotoxy(int x, int y) {

         printf("\033[%d;%df",y,x);

              fflush(stdout);

}




int main(void)
{

    char put[50];//입력단어 배열
    int cnt = 0;//시도횟수 0으로 초기화
    char *ans[] = {"parameter", "ASCII", "main", "&pt", "fgets", "fprintf",  }; //   정답 단어 등록
    int wnum = sizeof(ans)/sizeof(char *);  // 정답 단어의 개수
    int i; //문자를 차례대로 비교하기 위한 변수
    int l;//길이
    char *word; //임의의 단어 포인터 배열
    char *pword;//화면에 출력되는 단어 배열
    int sel; // 난수
    srand(time(NULL));                // 시간을 기준으로 초기화되는 난수 생성 함수
    sel = rand() % wnum;             // 0~ wnum-1 범위의 난수 생성
    word = ans[sel];                 // 임의의 단어 포인터
    l = strlen(word);                //strlen함수 문자열의 길이구함  단어의 길이
    pword = (char *)malloc(l + 1);   // 단어의 길이 +1 만큼 할당된 메모리 주소를 char형으로 변환하여 화면에 나타나는 단어 배열
    
   
      for(i=0; i <l; i++)
        pword[i] = '?';     //  화면에 나타나는 단어 ? 로 초기화
        pword[l] = '\0';
        system("clear"); //출력창 깨끗이
      
        gotoxy(0,1);  printf("==========================================================================\n");                                       
        gotoxy(0,2);  printf("=                       ? G a m e                                        =\n");
        gotoxy(0,3);  printf("=                  Second game is ? game.                                =\n");
        gotoxy(0,4);  printf("=               Reads and answers questions                              =\n");
        gotoxy(0,5);  printf("=       Enter only one character to enter the blank space                =\n");
        gotoxy(0,6);  printf("=                                                                        =\n");
        gotoxy(0,7);  printf("==========================================================================\n");

    /* 정답단어에 따라서 출력되는 문제*/
     {  if(word[0] == 'p')
        printf("<Question>The data the function needs to perform its work (given from the outside)");
        if(word[0] == 'A')
            printf("<Question>This code is a method of expressing the symbols used by a person in a computer.");
        if(word[0] == 'm')
            printf("<Question>What function must be present in every C language program?");
        if(word[0] == '&')
            printf("<Question>When you declare variables as follows,What are the different values?\n int a[5]=1,2,3,4,5;\n int *pt=    a;\n < pt, a, &a, &pt>\n");
        if(word[1] == 'g')
            printf("<Question>A function that reads and returns a single line from a file");
        if(word[1] == 'f')
            printf("<Question>Functions used to store a text file as a string, either as a real number or as an integer");

    }
   while (1)
     {
        printf("\nA n s w e r  : %s  ", pword);

        fgets(put, sizeof(put), stdin);  //  문자입력

        cnt++;                                    // 시도 회수 카운트

         for(i=0; i <l; i++)
            if(pword[i] == '?' && word[i] == put[0])   // 입력된 문자가 아직 가려져 있고 입력한 문자가 정답 단어에 있으면
                pword[i] = put[0]; //?에 입력한 문자 출력
                put[strlen(put)-1] = '\0';

         for(i=0; i <l; i++)
            if(pword[i] == '?') //?인 문자가 있으면 반복
                break;         


            if(i == l) {      // 가려진 문자가 없으면(정답단어를 맞췄으면)
                printf("\nCongratulations!! \n Answer is %s.\nYou tried %dtimes and got the right answer.",pword,cnt
                 );
            return 0;
        }
    }
    return 0;
}


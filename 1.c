#include <stdio.h>
#include <stdlib.h> //srand�Լ��� rand �Լ� ���� ����
#include <string.h> //strlen�Լ� ���� ����
#include <memory.h>
#include <time.h>//time �Լ� ���� ����



void gotoxy(int x, int y) {

         printf("\033[%d;%df",y,x);

              fflush(stdout);

}




int main(void)
{

    char put[50];//�Է´ܾ� �迭
    int cnt = 0;//�õ�Ƚ�� 0���� �ʱ�ȭ
    char *ans[] = {"parameter", "ASCII", "main", "&pt", "fgets", "fprintf",  }; //   ���� �ܾ� ���
    int wnum = sizeof(ans)/sizeof(char *);  // ���� �ܾ��� ����
    int i; //���ڸ� ���ʴ�� ���ϱ� ���� ����
    int l;//����
    char *word; //������ �ܾ� ������ �迭
    char *pword;//ȭ�鿡 ��µǴ� �ܾ� �迭
    int sel; // ����
    srand(time(NULL));                // �ð��� �������� �ʱ�ȭ�Ǵ� ���� ���� �Լ�
    sel = rand() % wnum;             // 0~ wnum-1 ������ ���� ����
    word = ans[sel];                 // ������ �ܾ� ������
    l = strlen(word);                //strlen�Լ� ���ڿ��� ���̱���  �ܾ��� ����
    pword = (char *)malloc(l + 1);   // �ܾ��� ���� +1 ��ŭ �Ҵ�� �޸� �ּҸ� char������ ��ȯ�Ͽ� ȭ�鿡 ��Ÿ���� �ܾ� �迭
    
   
      for(i=0; i <l; i++)
        pword[i] = '?';     //  ȭ�鿡 ��Ÿ���� �ܾ� ? �� �ʱ�ȭ
        pword[l] = '\0';
        system("clear"); //���â ������
      
        gotoxy(0,1);  printf("==========================================================================\n");                                       
        gotoxy(0,2);  printf("=                       ? G a m e                                        =\n");
        gotoxy(0,3);  printf("=                  Second game is ? game.                                =\n");
        gotoxy(0,4);  printf("=               Reads and answers questions                              =\n");
        gotoxy(0,5);  printf("=       Enter only one character to enter the blank space                =\n");
        gotoxy(0,6);  printf("=                                                                        =\n");
        gotoxy(0,7);  printf("==========================================================================\n");

    /* ����ܾ ���� ��µǴ� ����*/
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

        fgets(put, sizeof(put), stdin);  //  �����Է�

        cnt++;                                    // �õ� ȸ�� ī��Ʈ

         for(i=0; i <l; i++)
            if(pword[i] == '?' && word[i] == put[0])   // �Էµ� ���ڰ� ���� ������ �ְ� �Է��� ���ڰ� ���� �ܾ ������
                pword[i] = put[0]; //?�� �Է��� ���� ���
                put[strlen(put)-1] = '\0';

         for(i=0; i <l; i++)
            if(pword[i] == '?') //?�� ���ڰ� ������ �ݺ�
                break;         


            if(i == l) {      // ������ ���ڰ� ������(����ܾ ��������)
                printf("\nCongratulations!! \n Answer is %s.\nYou tried %dtimes and got the right answer.",pword,cnt
                 );
            return 0;
        }
    }
    return 0;
}


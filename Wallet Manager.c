#include <stdio.h>

struct  AccType
{
    int AccBal;
}DBBL,Rocket,bKash,Payoneer;

void DBBLf();
void Rocketf();
void bKashf();
void Payoneerf();

int main()
{
    int Selection1,Selection2,Selection3;
    int TmpVar1,TmpVar2,TmpVar3;
    int SystemPass;
    char again1,again2;

    SystemPass=1234;
    again1='y';
    again2='y';

    while(again1=='y')
    {
        printf("Please Enter The System Password: ");
        scanf("%d",&TmpVar1);

        system("cls");

        if(SystemPass==TmpVar1)
        {
            while(again2=='y')
            {
                printf("Which account information you want to see?\n 1.DBBL\n 2.Rocket\n 3.bKash\n 4.Payoneer.\n");
                Selection1=getche();

                system("cls");

                switch(Selection1)
                {
                case '1':
                    DBBLf();
                    break;

                case '2':
                    Rocketf();
                    break;

                case '3':
                    bKashf();
                    break;

                case '4':
                    Payoneerf();
                    break;
                }

                system("cls");

                printf("Would you like to see another information?(y/n)");
                again2=getche();

                system("cls");
            }
        }

        else
        {
            printf("Sorry,Password was incorrect.Would you like to try again?(y/n)");
            again1=getche();
        }
    }
    return 0;
}

void DBBLf()
{
    FILE *fp=fopen("WalletManager.txt","at+");

    int Selection;
    int TmpVar;

    printf("Which act you want to play?\n 1.View Balance\n 2.Add Balance\n 3.Cut Balance\n");
    Selection=getche();

    switch(Selection)
    {
    case '1':
        fscanf(fp,"%d",&DBBL.AccBal);
        printf("Your DBBL balance is %d",DBBL.AccBal);
        break;

    case '2':
        fscanf(fp,"%d",&DBBL.AccBal);
        printf("%d+",DBBL.AccBal);
        scanf("%d",&TmpVar);
        DBBL.AccBal+=TmpVar;
        fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);
        fprintf(fp,"%d",DBBL.AccBal);
        break;

    case '3':
        fscanf(fp,"%d",&DBBL.AccBal);
        printf("%d-",DBBL.AccBal);
        scanf("%d",&TmpVar);
        DBBL.AccBal-=TmpVar;
        fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);
        fprintf(fp,"%d",DBBL.AccBal);
        break;
    }
}

void Rocketf()
{
    printf("This module is on development process.Please try again later.");
}

void bKashf()
{
    printf("This module is on development process.Please try again later.");
}

void Payoneerf()
{
    printf("This module is on development process.Please try again later.");
}

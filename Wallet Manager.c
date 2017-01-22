#include <stdio.h>             //declaring standard library

struct  AccType                  //declaring structure for later use
{
    int AccBal;
}DBBL,Rocket,bKash,Payoneer;

void DBBLf();                 //declaring function for later use
void Rocketf();
void bKashf();
void Payoneerf();

int main()
{
    int Selection1,Selection2,Selection3;            //declaring some variable
    int TmpVar1,TmpVar2,TmpVar3;
    int SystemPass;
    char again1,again2;

    SystemPass=1234;
    again1='y';
    again2='y';

    while(again1=='y')
    {
        printf("Please Enter The System Password: ");           //asking user for system password
        scanf("%d",&TmpVar1);                                //put user password in TmpVar1 variable

        system("cls");                             //clearing the console screen

        if(SystemPass==TmpVar1)                  //if the user input password is similar to system password then this part will work
        {
            while(again2=='y')
            {
                printf("Which account information you want to see?\n 1.DBBL\n 2.Rocket\n 3.bKash\n 4.Payoneer.\n");
                Selection1=getche();              //taking input from the user

                system("cls");

                switch(Selection1)                 //and switch to the part which user want to see
                {
                case '1':
                    DBBLf();                //if user press 1 then program will search DBBLf function and take command from there
                    break;

                case '2':
                    Rocketf();                    //if user press 2 then program will search Rocketf function and take command from there
                    break;

                case '3':                 //if user press 3 then program will search bkashf function and take command from there
                    bKashf();
                    break;

                case '4':
                    Payoneerf();              //if user press 4 then program will search Payoneerf function and take command from there
                    break;
                }

                system("cls");           //clearing the console screen

                printf("Would you like to see another information?(y/n)");       //asking user does he/she want to do another work
                again2=getche();            //if user press y then while loop will work once more time

                system("cls");              //clearing console screen
            }
        }

        else
        {
            printf("Sorry,Password was incorrect.Would you like to try again?(y/n)");          //if the user input password isn't valid then show an error message
            again1=getche();
        }
    }
    return 0;
}

void DBBLf()                      //DBBLf function
{
    FILE *fp=fopen("WalletManager.txt","a");              //opening file on append mode

    int Selection;                //declaring some variable
    int TmpVar;

    printf("Which act you want to play?\n 1.View Balance\n 2.Add Balance\n 3.Cut Balance\n");
    Selection=getche();                     //asking user what he/she wants to do and take input

    switch(Selection)
    {
    case '1':
        fscanf(fp,"%d",&DBBL.AccBal);                      //read input from file and put that to DBBL.AccBal structure variable
        printf("Your DBBL balance is %d",DBBL.AccBal);               //show the current dbbl balance
        break;               //break the switching

    case '2':
        fscanf(fp,"%d",&DBBL.AccBal);                  //reading data from file
        printf("%d+",DBBL.AccBal);
        scanf("%d",&TmpVar);
        DBBL.AccBal+=TmpVar;
        fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);                 //move the cursor position where DBBL.AccBal is situated
        fprintf(fp,"%d",DBBL.AccBal);                        //update the balance
        break;

    case '3':
        fscanf(fp,"%d",&DBBL.AccBal);
        printf("%d-",DBBL.AccBal);
        scanf("%d",&TmpVar);
        DBBL.AccBal-=TmpVar;
        fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);             //move the cursor position where DBBL.AccBal is situated
        fprintf(fp,"%d",DBBL.AccBal);                              //update the balance
        break;
    }
}

void Rocketf()
{
    printf("This module is on development process.Please try again later.");              //this code has some bug and developer is fixing the problem instead of adding more feature
}

void bKashf()                                                                           //so there are no code to work
{
    printf("This module is on development process.Please try again later.");              //soon this feature will added :)
}

void Payoneerf()
{
    printf("This module is on development process.Please try again later.");
}

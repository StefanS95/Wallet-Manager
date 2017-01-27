#include <stdio.h>

void DBBL(void);
void Rocket(void);
void bKash(void);
void Payoneer(void);
void ViewBalance(void);
void AddBalance(void);
void CutBalance(void);

struct AccType
{
	int AccBal;
	//char password[20];
};

int systemPass = 1234;
int TmpVar;

//enum AccountType {DBBL = 1, Rocket, bKash, Payoneer};

int main(void)
{
	int temp, selection;

	do {
		printf("Please Enter The System Password: ");
		scanf(" %d", &temp);
	} while(temp != systemPass);

	printf("Which account information you want to see?\n 1.DBBL\n 2.Rocket\n 3.bKash\n 4.Payoneer.\n");
	scanf(" %d", &selection);

	switch(selection)
	{
		case 1:
			DBBL();
			break;
		case 2:
			Rocket();
			break;
		case 3:
			bKash();
			break;
		case 4:
			Payoneer();
			break;
		default:
			printf("Invalid Input!");
	}

	return 0;
}

void DBBL(void)
{
	int selection;

	printf("Which act you want to play?\n 1.View Balance\n 2.Add Balance\n 3.Cut Balance\n");
	scanf(" %d", &selection);

	switch(selection)
	{
		case 1:
			ViewBalance();
			break;

	    case 2:
	    	AddBalance();
	    	break;

	    case 3:
	    	CutBalance();
	    	break;
	      
	     default:
	     	printf("Invalid Input!");
	}
}

void Rocket()
{
    printf("This module is on development process.Please try again later.");              //this code has some bug and developer is fixing the problem instead of adding more feature
}

void bKash()                                                                           //so there are no code to work
{
    printf("This module is on development process.Please try again later.");              //soon this feature will added :)
}

void Payoneer()
{
    printf("This module is on development process.Please try again later.");
}


void ViewBalance(void)
{
	struct AccType DBBL;
	FILE *fp = fopen("WalletManager.txt","rb");
	if(!fp) {
		//printf("Not Found!\n");
		//return;
		DBBL.AccBal = 0;
	}
	else
    	fread(&DBBL, sizeof(DBBL), 1, fp);                 //read input from file and put that to DBBL.AccBal structure variable
    printf("Your DBBL balance is %d\n",DBBL.AccBal);               //show the current dbbl balance
    fclose(fp);
}

void AddBalance(void)
{
	struct AccType DBBL;
	FILE *fp = fopen("WalletManager.txt","rb");
	if(!fp) {
		//printf("Not Found!\n");
		fp = fopen("WalletManager.txt","wb");
		DBBL.AccBal = 0;
	}
	else
		fread(&DBBL, sizeof(DBBL), 1, fp);                  //reading data from file

    printf("%d+",DBBL.AccBal);
    scanf("%d",&TmpVar);
    DBBL.AccBal+=TmpVar;
 	fp = freopen("WalletManager.txt", "wb", fp);                 									
    fwrite(&DBBL, sizeof(DBBL), 1, fp);                       //update the balance
    printf("Your balance is updated successfully.\nNew balance: %d\n", DBBL.AccBal);
    fclose(fp);

}

void CutBalance(void)
{
	struct AccType DBBL;
	FILE *fp = fopen("WalletManager.txt","rb");
	if(!fp) {
		//printf("Not Found!\n");
		fp = fopen("WalletManager.txt","wb");
		DBBL.AccBal = 0;
	}
	else
		fread(&DBBL, sizeof(DBBL), 1, fp);     
		             						//reading data from file
    printf("%d-",DBBL.AccBal);
    scanf("%d",&TmpVar);
    DBBL.AccBal-=TmpVar;
 	fp = freopen("WalletManager.txt", "wb", fp);                 			
    fwrite(&DBBL, sizeof(DBBL), 1, fp);                       //update the balance
    printf("Your balance is updated successfully.\nNew balance: %d\n", DBBL.AccBal);
    fclose(fp);
}
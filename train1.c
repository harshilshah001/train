//Train ticket booking allotment system
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


//Global variables
typedef struct{ //this defines a new type pd of the given structure; given structure is a new type named pd
//now we can use new object of this structure using pd
	char name[50];
	int train_num;
	int num_of_seats;
}pd; //


//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);								
void printticket(char name[],int,int,float);	//print ticket 
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();


//main function declaration
int main()

{
		system("cls"); 
	printf("TRAIN TICKET RESERVATION SYSTEM\n");
	    
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
    //system(“cls”) is used to make the screen/terminal clear
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("TRAIN RESERVATION SYSTEM");
	printf("\n");
	printf("\n1>> Reserve A Ticket");
	printf("\n");
	printf("\n2>> View All Available Trains");
	printf("\n");
	printf("\n3>> Cancel Reservation");
	printf("\n");
	printf("\n4>> Exit");
	printf("\n");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1002tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1003\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1004\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1005\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1006\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1007\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1008\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
	printf("\n1009\tRajdhani\tAhmedabad to Delhi\tRs.900\t\t9pm");
    
}

//reservation
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("\n Reservation Done\n");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

//charges

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}


//printticket

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

//Train specification

void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1006)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1007)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\nTrain:\t\t\tRajdhani");
		printf("\nDestination:\t\tAhmedabad to Delhi");
		printf("\nDeparture:\t\t9pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\nLOGIN FORM\n  ");
    printf(" \nENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \nENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \nYOUR LOGIN IS SUCCESSFUL");
	printf("\nPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\nLOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

void cancel(void)
{
	
	system("cls");
	int trainnum;
		printf("Enter the train number: \n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled");  
		getch();
}

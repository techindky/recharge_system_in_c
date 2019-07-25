#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.cpp"
#include "adminLogin.cpp"
#include "newCustomer.cpp"
#include "existingUser.cpp"

void start();
void display1(char*);
FILE* getFile(int);
void addPlan();
void updatePlan();
void deletePlan();

int main() {
    start();
}

void start() {
	int select;

    printf("1.NEW CUSTOMER\n");
    printf("2.EXISTING CUSTOMER\n");
    printf("3.ADMINISTRACTOR\n");
    printf("4.EXIT\n");
	scanf("%d", &select);

    switch(select) {
        case 1: 
            newCustomer();
			break;
        case 2:
            existingUser();
			break;
        case 3:
            adminLogin();
			break;
        case 4:
            exit(0);
			break;
        default:
            printf("Wrong choice entered");
    }
}

void showAdminOptions() {
	int choice, ch;
	printf("What do you want to do\n");
	printf("1.ADD\n");
	printf("2.UPDATE\n");
	printf("3.DELETE\n");
	printf("4.Exit\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			addPlan();
			break;
		case 2:
			updatePlan();
			break;
		case 3:
			deletePlan();
			break;
		case 4:
			exit(0);
			break;
		default: 
			printf("Sorry! Wrong choice entered");
			showAdminOptions();
	}
}

void addPlan() {
	char plans[1000];
	FILE *fp;
	int choice;
	printf("Choose category to add plan in it\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	scanf("%d", &choice);

	fp = getFile(choice);
	char c;
	do 
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	while(c != EOF);
	fclose(fp);
	printf("\nEnter the plan details you want to add\n");
	fgets(plans, 500, stdin);
	scanf("%[^\n]s", plans);
	fp = fopen(planFiles[choice - 1] , "a");
	fprintf(fp, "\n%s", plans);
	fclose(fp);

	showAdminOptions();
}

void updatePlan() {
	char str[100], plan[200];
	int choice, lineNo = 0, updateLineNo;
	FILE *fp1, *fp2;

	printf("Choose category to update plan in it\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	scanf("%d", &choice);

	fp1 = getFile(choice);
	while(fgets(str, 200, fp1) != NULL)
	{
		lineNo++;
		printf("%d. %s", lineNo, str);
	}
	lineNo = 0;
	rewind(fp1);

	printf("\nEnter the line no. you want to update : ");
	scanf("%d", &updateLineNo);

	printf("Enter the plan you want to update with old one: \n");
	fgets(plan, 100, stdin);
	scanf("%[^\n]s", plan);

	fp2 = fopen("replica.txt", "w");

	while(fgets(str, 200, fp1) != NULL)
	{
		lineNo++;
		if(lineNo != updateLineNo)
		{
			fputs(str, fp2);
		}
		else if(lineNo == updateLineNo)
		{
			fprintf(fp2, "%s\n", plan);
		}
	}
	fclose(fp1);
	fclose(fp2);

	remove(planFiles[choice - 1]);
	rename("replica.txt", planFiles[choice - 1]);

	showAdminOptions();
}

void deletePlan() {
	char plans[1000], str[200];
	int choice, deletedLineNo, lineNo = 0;
	FILE *fp1, *fp2;

	printf("Choose category to delete any plan from it\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	scanf("%d", &choice);
		
	fp1 = getFile(choice);
	while(fgets(str, 199, fp1) != NULL)
	{
		lineNo++;
		printf("%d. %s", lineNo, str);
	}
	lineNo = 0;
	rewind(fp1);

	printf("\nEnter the line no. you want to update : ");
	scanf("%d", &deletedLineNo);

	fp2 = fopen("replica.txt", "w");

	while(fgets(str, 199, fp1) != NULL)
	{
		lineNo++;
		if(lineNo != deletedLineNo)
		{
			fputs(str, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);

	remove(planFiles[choice - 1]);
	rename("replica.txt", planFiles[choice - 1]);

	showAdminOptions();
}

void rechargeOptions() {
	int serviceProvider, ch2 = 1;
	char mno[15], data[300];
	FILE *fp, *fc;

	struct customer ct;
	printf("Choose your service provider\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	printf("4.Exit\n");
	scanf("%d", &serviceProvider);
		
	switch(serviceProvider)
	{
		case 1:
		{	
			fp = getFile(serviceProvider);
			char c;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			bool found = false;
			printf("\n\nEnter your mobile number : ");
			scanf("%s", mno);
			fc = fopen("customer.txt", "r");
			while(fscanf(fc, "%s", data) != EOF){
				switch(ch2)
				{
					case 1: 
						strcpy(ct.name, data);
						ch2++;
						break;
					case 2:
						strcpy(ct.email, data);
						ch2++;
						break;
					case 3:
						strcpy(ct.idProof, data);
						ch2++;
						break;
					case 4:
						strcpy(ct.gender, data);
						ch2++;
						break;
					case 5:
						strcpy(ct.nationality, data);
						ch2++;
						break;
					case 6:
						strcpy(ct.DOB, data);
						ch2++;
						break;
					case 7:
						strcpy(ct.serviceProvider, data);
						ch2++;
						break;
					case 8:
						strcpy(ct.mobileNumber, data);
						ch2 = 1;
						if(strcmp(ct.serviceProvider, operators[0]) == 0 && strcmp(ct.mobileNumber, mno) == 0)
						{
							found = true;
						}
						break;
				}
				if(found){
					break;
				}
			}
			if(found){
				display1(mno);
			}
			break;
		}
		case 2:
		{
			fp = getFile(serviceProvider);
			char c;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			bool found = false;
			printf("\n\nEnter your mobile number : ");
			scanf("%s", mno);
			fc = fopen("customer.txt", "r");
			while(fscanf(fc, "%s", data) != EOF){
				switch(ch2)
				{
					case 1: 
						strcpy(ct.name, data);
						ch2++;
						break;
					case 2:
						strcpy(ct.email, data);
						ch2++;
						break;
					case 3:
						strcpy(ct.idProof, data);
						ch2++;
						break;
					case 4:
						strcpy(ct.gender, data);
						ch2++;
						break;
					case 5:
						strcpy(ct.nationality, data);
						ch2++;
						break;
					case 6:
						strcpy(ct.DOB, data);
						ch2++;
						break;
					case 7:
						strcpy(ct.serviceProvider, data);
						ch2++;
						break;
					case 8:
						strcpy(ct.mobileNumber, data);
						ch2 = 1;
						if(strcmp(ct.serviceProvider, operators[1]) == 0 && strcmp(ct.mobileNumber, mno) == 0)
						{
							found = true;
						}
						break;
				}
				if(found){
					break;
				}
			}
			if(found){
				display1(mno);
			}
			break;
		}
		case 3:
		{
		fp = getFile(serviceProvider);
			char c;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			bool found = false;
			printf("\n\nEnter your mobile number : ");
			scanf("%s", mno);
			fc = fopen("customer.txt", "r");
			while(fscanf(fc, "%s", data) != EOF){
				switch(ch2)
				{
					case 1: 
						strcpy(ct.name, data);
						ch2++;
						break;
					case 2:
						strcpy(ct.email, data);
						ch2++;
						break;
					case 3:
						strcpy(ct.idProof, data);
						ch2++;
						break;
					case 4:
						strcpy(ct.gender, data);
						ch2++;
						break;
					case 5:
						strcpy(ct.nationality, data);
						ch2++;
						break;
					case 6:
						strcpy(ct.DOB, data);
						ch2++;
						break;
					case 7:
						strcpy(ct.serviceProvider, data);
						ch2++;
						break;
					case 8:
						strcpy(ct.mobileNumber, data);
						ch2 = 1;
						if(strcmp(ct.serviceProvider, operators[2]) == 0 && strcmp(ct.mobileNumber, mno) == 0)
						{
							found = true;
						}
						break;
				}
				if(found){
					break;
				}
			}
			if(found){
				display1(mno);
			}
			break;
		}
		case 4:
			exit(0);
		default: 
			printf("Wrong choice!");
			rechargeOptions();
	}
}

FILE *getFile(int choice) {
	int arraylen = sizeof(planFiles)/sizeof(planFiles[0]);
	for(int i = 0; i < arraylen; i++) {
		if(choice - 1 == i) {
			return fopen(planFiles[i], "r");
		}
	}
	showAdminOptions();
}

void checkBalance() {
	FILE *fa;
	int ch2 = 1, i;
	char mno[50], data[300];
	fa = fopen("account_details.txt","r");
	bool found = false;
	printf("Enter mobile number:  ");
	scanf("%s", mno);

	while(fscanf(fa, "%s", data) != EOF)
	{
		switch (ch2)
		{
			case 1:
				strcpy(ad.name, data);
				ch2++;
				break;
			case 2:
				strcpy(ad.mb_no, data);
				ch2++;
				break;
			case 3:
				strcpy(ad.balance, data);
				ch2++;
				break;
			case 4:
				strcpy(ad.validity, data);
				ch2 = 1;
				if(strcmp(mno, ad.mb_no) == 0)
				{
					found = true;
				}
				break;				
		}		
		
		if(found)
			break;
	}
	fclose(fa);

	if(found)
	{
		printf("\nYour mobile number is: %s\nYour current balance is Rs %s\nand valid for %s days.",
		ad.mb_no,ad.balance,ad.validity);

		printf("Press 1 for back or 0 for exit\n");
		scanf("%d", &i);

		(i == 1) ? customerOptions() : exit(0);
	} else {
		printf("There are no records in the file......");
	}
}

void browsePlans() {
	FILE *fp;
	int i;

	printf("Select your service_provider :\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	scanf("%d", &i);

	switch(i) 
	{
		case 1:
		{
			fp = getFile(i);
			char c;
			int ch;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			printf("\nPress 1 for back or 0 for exit");
			scanf("%d", &ch);
			(ch == 1) ? customerOptions() : exit(0);
			break;
		}	
		case 2:
		{
			fp = getFile(i);
			char c;
			int ch;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			printf("\nPress 1 for back or 0 for exit");
			scanf("%d", &ch);
			(ch == 1) ? customerOptions() : exit(0);
			break;
		}
		case 3:
		{
			fp = getFile(i);
			char c;
			int ch;
			do 
			{
				c = fgetc(fp);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fp);
			printf("\nPress 1 for back or 0 for exit");
			scanf("%d", &ch);
			(ch == 1) ? customerOptions() : exit(0);
			break;
		}
	}
}

void customerOptions() {
	int sp;

	printf("Choose option\n");
	printf("1.Check Balance\n");
	printf("2.Browse Plans\n");
	printf("3.Recharge Now\n");
	printf("4.Exit\n");
	scanf("%d", &sp);
	switch(sp) {
		case 1:
			checkBalance();
			break;
		case 2:
			browsePlans();
			break;
		case 3:
			rechargeOptions();
			break;
		case 4:
			exit(0);
			break;
		default :
			printf("incorrect choice");
			customerOptions();
			break;
	}
}

void display1(char number[15]) {
	FILE *fp1, *fp2;
	int ch2 = 1, k = 0, line = 1;
	char data[300], str[200], amount[3];
	fp1 = fopen("account_details.txt","r");
	bool found = false;

	while(fscanf(fp1, "%s", data) != EOF)
	{
		switch (ch2)
		{
			case 1:
				strcpy(ad.name, data);
				ch2++;
				break;
			case 2:
				strcpy(ad.mb_no, data);
				ch2++;
				break;
			case 3:
				strcpy(ad.balance, data);
				ch2++;
				break;
			case 4:
				strcpy(ad.validity, data);
				ch2 = 1;
				if(strcmp(number, ad.mb_no) == 0)
				{
					found = true;
				}
				k++;
				break;				
		}		
		if(found)
			break;
	}	
		if(found) {
			printf("\nEnter the amount: ");
			scanf("%s", amount);
			strcpy(ad.balance, amount);
			printf("%s", ad.balance);
			fp2 = fopen("replica.txt", "w");
			while(fgets(str, 100, fp1) != NULL) {
				if(line != k) {
					fputs(str, fp2);
				}
				else if(line == k) {
					fprintf(fp2, "%s %s %s %s\n", ad.name, ad.mb_no, ad.balance, ad.validity);
				}
				line++;
			}
		}	
	
			fclose(fp1);
			fclose(fp2);

			remove("account_details.txt");
			rename("replica.txt", "account_details.txt");

			printf("Recharge sucessful...");
}
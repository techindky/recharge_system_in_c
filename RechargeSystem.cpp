#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
	char name[20];
	char email[50];
	char idProof[50];
	char gender[10];
	char nationality[20];
	char DOB[15];
} EMPTY_CUST_STRUCT;

const char operators[][13] = { "Airtel", "Vodafone", "Reliance Jio" };
const char planFiles[][16] = { "airtel_plans.txt", "vodafone_plans.txt", "reliance_jio.txt" };

void addPlan();
void updatePlan();
void deletePlan();
FILE *getFile(int);
void rechargeOptions();
void showAdminOptions();
void adminLogin();
void existingUser();
void newCustomer();

int main() {
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
            main();
    }
}

void newCustomer() {
    FILE *cust;
    FILE *num;
	struct customer ct;
	
    cust = fopen("customer.txt", "a");

    printf("Enter your name:-\n");
	scanf("%s", ct.name);
	printf("Enter your email:-\n");
	scanf("%s", ct.email);
	printf("Which idProof do you have:-\n");
	scanf("%s", ct.idProof);
	printf("Your are (M/F):-\n");
	scanf("%s", ct.gender);
	printf("What is your nationality?\n");
	scanf("%s", ct.nationality);
	printf("Enter your date of birth in the (DD/MM/YYYY) format\n");
	scanf("%s", ct.DOB);
    printf("Congrulations! You are successfully registered...\n");
	printf("Your login_id is your email and password is your email and date of birth\n");
    
	fprintf(cust, "\n%s %s %s %s %s %s", ct.name, ct.email, ct.idProof, ct.gender, ct.nationality, ct.DOB);
    fclose(cust);
	printf("Your credentials will be the email and dob that are %s and %s respectively\n", ct.email, ct.DOB);

	int choose;
	
	printf("Choose your operator:\n");
	printf("1.%s\n", operators[0]);
	printf("2.%s\n", operators[1]);
	printf("3.%s\n", operators[2]);
	printf("Only press integers\n");
	scanf("%d", &choose);

    switch (choose)
    {
        case 1:
			{
				char number1[11] = "9932210003";
				printf("Your number is   %s\n", number1);
				num = fopen("numbers.txt", "a");
				fprintf(num, "%s\n", number1);
			}
            break;
        case 2:
			{
				char number2[11] = "7021548976";
				printf("Your number is %s\n", number2);
				num = fopen("numbers.txt", "a");
				fprintf(num, "%s\n", number2);
			}
			break;
        case 3:
			{
				char number3[11] = "8852164700";
				printf("Your number is   %s\n", number3);
				num = fopen("numbers.txt", "a");
				fprintf(num, "%s\n", number3);
			}
            break;    
        default:
            printf("Sorry! Wrong choice entered");
			exit(0);
    }   
}

void existingUser() {
    int choice;
	char id[50], p[50], data[1000];
	FILE *fp, *fs, *fd, *ft;

	struct customer ct;

	printf("\nEnter ID to login\n");
	scanf("%s", id);
	printf("Enter Password\n");
	scanf("%s", p);

	fp = fopen("customer.txt", "r");
	int infoCount = 1;

	while(fscanf(fp, "%s", data) != EOF)
	{
		switch (infoCount)
		{
			e
				} else {
					ct = EMPTY_CUST_STRUCT;
				}
				break;
		}

		if(infoCount == -1) {
			break;
		}
	}
	fclose(fp);

	if(strlen(ct.email) == 0)
	{
		printf("\nIncorrect ID and Password......\n\n");
	}
	else {
		printf("login successfully......\n");
		rechargeOptions();		
	}
		
}

void adminLogin() {
    char id[20], p[20], login_id[50], password[50];
	int size;

	FILE *fp;

	fp = fopen("admin_login.txt", "r");
	if (fp != NULL) {
    	fseek (fp, 0, SEEK_END);
    	size = ftell(fp);

    	if (size == 0) 
		{
			fp = fopen("admin_login.txt", "w");
			printf("No Admin till yet....\n");
			printf("Enter ID to register\n");
			scanf("%s",login_id);
			printf("Enter Password\n");
			scanf("%s",password);

			fprintf(fp, "%s\n %s", login_id, password);
			printf("Id created!!!!\n");	
			fclose(fp);
		}
	}	
	fp = fopen("admin_login.txt", "r");
	fscanf(fp, "%s[^\n]", login_id);
	fscanf(fp, "%s[^\n]", password);

		
	printf("Enter ID to login\n");
	scanf("%s", id);
	printf("Enter Password\n");
	scanf("%s", p);
	
	if(strcmp(login_id,id) == 0 && strcmp(password,p) == 0)
	{
		printf("login successfully...............\n");
		showAdminOptions();
	}
	else{
		printf("Incorrect ID and Password......\n");
		adminLogin();
	}
	fclose(fp);
}

void showAdminOptions() {
	int choice;
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

void deletePlan(){
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
	int serviceProvider;
	FILE *fs, *fd, *ft;
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
			fs = getFile(serviceProvider);
			char c;

			do 
			{
				c = fgetc(fs);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fs);			
			printf("\nYour current balance is Rs 400\n");
			int x, y;
				
			printf("Enter the amount of the pack you want to recharge\n");
			scanf("%d", &x);
				
			y = 400 - x;
			
			if(x <= 400)
			{
				printf("Recharge Successful\n");
				printf("Your remaining balance is Rs %d", y);
			}
			else
			{
				printf("Sorry! Invalid amount entered");		
			}
			break;
		}
		case 2:
		{
			ft = getFile(serviceProvider);
			char c;
			do 
			{
				c = fgetc(ft);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(ft);
			printf("\nYour current balance is Rs 400\n");
			int x, y;
			printf("Enter the amount of the pack you want to recharge\n");
			scanf("%d", &x);
			y = 400 - x;
			if(x <= 400)
			{
				printf("Recharge Successful\n");
				printf("Your remaining balance is Rs %d", y);
			}
			else
			{
				printf("Sorry! Invalid amount entered");
			}
			break;
		}
		case 3:
		{
			fd = getFile(serviceProvider);
			char c;
			do {
				c = fgetc(fd);
				printf("%c", c);
			}
			while(c != EOF);
			fclose(fd);
			printf("\nYour current balance is Rs 400\n");
			int x, y;
			printf("Enter the amount of the pack you want to recharge\n");
			scanf("%d", &x);
			y = 400 - x;
			if(x <= 400){
				printf("Recharge Successful\n");
				printf("Your remaining balance is Rs %d", y);
			}
			else
			{
				printf("Sorry! Invalid amount entered");
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
			return fopen(strcat(planFiles[i], ".txt"), "r");
		}
	}

	showAdminOptions();
}
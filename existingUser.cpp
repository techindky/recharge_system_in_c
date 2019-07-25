int main();
void customerOptions();

void existingUser() {
	char id[50], p[50], data[1000];
	FILE *fp;

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
			case 1:
				strcpy(ct.name, data);
				infoCount++;
				break;
			case 2:
				strcpy(ct.email, data);
				infoCount++;
				break;
			case 3:
				strcpy(ct.idProof, data);
				infoCount++;
				break;
			case 4:
				strcpy(ct.gender, data);
				infoCount++;
				break;
			case 5:
				strcpy(ct.nationality, data);
				infoCount++;
				break;
			case 6:
				strcpy(ct.DOB, data);
				infoCount = 1;
				break;
		}

		if(strcmp(ct.email, id) == 0 && strcmp(ct.DOB, p) == 0) {
			infoCount = 0;
			break;
		}
	}
	fclose(fp);

	if(infoCount == 0)
	{
		printf("login successfully......\n");
		customerOptions();		
	}
	else {
		printf("\nIncorrect ID and Password......\n\n");
		printf("first register yourself from the main menu\n");
		main();
	}	
}
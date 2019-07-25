void newCustomer() {
    FILE *cust, *fp;
	int count;
	char data[300], details[300];
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
	printf("Enter the service provider(Airtel/Vodafone/RelianceJio)\n");
	scanf("%s", ct.serviceProvider);
	if(strcmp(ct.serviceProvider, "Airtel") == 0 || strcmp(ct.serviceProvider, "Vodafone") == 0 || 
		strcmp(ct.serviceProvider, "RelianceJio") == 0){
			count = 1;
		}
	else {
		printf("invalid service provider");
		exit(0);
	}
	printf("Enter mobile number you want: \n");
	scanf("%s", ct.mobileNumber);
    printf("Congrulations! You are successfully registered...\n");
	fprintf(cust, "\n%s %s %s %s %s %s %s %s", ct.name, ct.email, ct.idProof, ct.gender, ct.nationality, ct.DOB, ct.serviceProvider
	, ct.mobileNumber);
    fclose(cust);
	printf("Your credentials will be the email and dob that are %s and %s respectively\n", ct.email, ct.DOB);
	fp = fopen("account_details", "a");
	fprintf(fp, "\n%s %s 0 28", ct.name, ct.mobileNumber);
	fclose(fp);
}
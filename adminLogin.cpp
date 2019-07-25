int main();
void showAdminOptions();

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
		main();
	}
	fclose(fp);
}
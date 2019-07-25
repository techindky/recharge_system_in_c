struct customer {
	char name[20];
	char email[50];
	char idProof[50];
	char gender[10];
	char nationality[20];
	char DOB[15];
	char mobileNumber[12];
	char serviceProvider[15];
} EMPTY_CUST_STRUCT;

struct account_details
{
	char name[100];
	char mb_no[50];
	char balance[100];
	char validity[20];
} ad;

struct number
{
	char op[30];
	char numb[20];
}num;

const char operators[][13] = { "Airtel", "Vodafone", "RelianceJio" };
const char planFiles[][30] = { "airtel_plans.txt", "vodafone_plans.txt", "reliance_jio.txt" };
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAX_LENGTH 1000

typedef struct user
{
	char msisdn[20];   //customer mobile number
	char opBrand[60];  //operator brand name
	char opMMC[20];    //operator mobile country code
	char callType[10]; //type of call : outgoing, incoming, smsMO, smsMT, GPRS
	char duration[10]; //call duration
	char download[10]; //mb downloaded
	char upload[10];   //mb uploaded
	char thirdPartyMsisdn[20];// third party mobile number
	char thirdPartyOpBrand[20];// third party operator brand name
}CUSTOMER;

typedef struct interOperator
{
	char opName[20];         //operator name
	char opMMC[20];          //operator country code
	long int incomingCall;   //total incoming calls duration
	long int outgoingCall;
	long int incomingSMS;
	long int outgoingSMS;
	long int downloaded;
	long int uploaded;
}INTOP;

void menu();
void logIn();
void signUp();
int authUser(char[], char[]);

int processMenu();

void billingMenu(CUSTOMER*);

void customerDetails(CUSTOMER*);

CUSTOMER* processCDR();

void customerBilling(CUSTOMER*);
void interOperatorBilling(CUSTOMER*);
void interOperatorBillingFile(CUSTOMER*);
void customerBillingFile(CUSTOMER*);



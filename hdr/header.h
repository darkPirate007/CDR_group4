#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_LENGTH 1000
#define LOG_LEVEL_INFO     1
#define LOG_LEVEL_WARNING  2
#define LOG_LEVEL_ERROR    3
#define LOG_LEVEL_FATAL    4

// Macro for logging messages
#define LOG(level, msg) \
    do { \
        if (level <= LOG_LEVEL_ERROR) { \
            printf("[%s] %s\n", log_levels[level], msg); \
        } \
    } while (0)


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
void signUp();
void logIn();
int authUser();

int processMenu();

void billingMenu(CUSTOMER*);

void billingMenuClient();

CUSTOMER* processCDR();

void interOperatorBillingClient();
void interOperatorBillingFile(CUSTOMER*);
void customerBillingFile(CUSTOMER*);
void customerBillingClient();

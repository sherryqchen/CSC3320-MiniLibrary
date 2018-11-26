/*
 ============================================================================
 Name        : miniLibrary.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

char userTxt[MAX] = "./User.txt";
char bookTxt[MAX] = "./Book.txt\0";
//char myAccountName[MAX], myPsw[MAX];
//static int userID = 0, userNum = 0;

typedef struct {
	int year;
	int month;
	int day;
}Date;

typedef struct {
	long userID;
	char firstName[MAX];
	char lastName[MAX];
	int accountName;
	char psw[MAX];
	char userType;
}User;

typedef struct {
	int bookID;
	char bookName[MAX];
	char author[MAX];
	char user[MAX];
	Date borrowD;
	Date dueD;
}Book;

// char *strsep(char **stringp, const char *delim) {
//   if (*stringp == NULL) { return NULL; }
//   char *token_start = *stringp;
//   *stringp = strpbrk(token_start, delim);
//   if (*stringp) {
//     **stringp = '\0';
//     (*stringp)++;
//   }
//   return token_start;
// }

int findUserByName(char myAccountName[], char myPsw[]){
	//printf("%s",path);
	char buffer[MAX];
	FILE *userInfo = fopen(userTxt, "r");
	if( !userInfo){
		printf("Failed to open User.txt\n");
		exit(1);
	}
	while(!feof(userInfo)){
		fgets(buffer, MAX, userInfo); // gets profile of user in buffer as char[]
		for(int i=0; i<4; i++){
			char *ptr =(strtok(buffer,","));
		}
		char account[MAX];
	        strcpy(account, ptr);
	       	if(strcmp(account,myAccountName) == 0){
			char *ptr = (strtok(buffer,","));
			char psw[MAX];
			strcpy(psw, ptr);
			if(strcmp(psw,myPsw) == 0){
				printf("Log in successfully.\n");
			}else{
				printf("Log in failed\n");
			}
			break;
		}
	}
	return EXIT_SUCCESS;
}

int main(void){
	char myAccountName[MAX], myPsw[MAX];
	printf("Enter your account name: ");
	scanf("%s", &myAccountName);
	printf("Enter your password: ");
	scanf("%s", &myPsw);
	findUserByName(myAccountName, myPsw);
	return EXIT_SUCCESS;
}



#include "pch.h"
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

char userTxt[MAX] = "./UserInfo.txt";
char bookTxt[MAX] = "./MyLibrary.txt";
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

int findUserByName(char myAccountName[], char myPsw[]) {
	//printf("%s",path);
	char buffer[MAX];
	FILE *userInfo = fopen(userTxt, "r+");
	if (!userInfo) {
		printf("Failed to open User.txt\n");
		exit(1);
	}
	while (!feof(userInfo)) {
		fgets(buffer, MAX, userInfo); // gets profile of user in buffer as char[]
		char *account, *psw, *userType;
		//Gets account info in account and compare.
		account = _strdup(buffer);
		account = strtok(account, ",");
		for (int i = 0; i < 3; i++) {
			account = strtok(NULL, ",");
		}
		//If account matched, compare password.
		if (strcmp(account, myAccountName) == 0) {
			psw = strtok(NULL, ",");
			if (strcmp(psw, myPsw) == 0) {
				printf("Log in successfully.\n");
				userType = strtok(NULL, "\n");
				if (strcmp(userType, "B") == 0) {
					printf("You are borrower.\n");
				}
				else if (strcmp(userType, "L") == 0) {
					printf("You are librarian.\n");
				}
				return EXIT_SUCCESS;
			}
		}	
	}
	printf("Log in failed\n");
	return EXIT_SUCCESS;
}

int main(void) {
	char myAccountName[MAX], myPsw[MAX];
	printf("Enter your account name: ");
	scanf("%s", &myAccountName);
	printf("Enter your password: ");
	scanf("%s", &myPsw);
	findUserByName(myAccountName, myPsw);
	return EXIT_SUCCESS;
}




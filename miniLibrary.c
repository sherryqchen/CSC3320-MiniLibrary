/*
 ============================================================================
 Name        : miniLibrary.c
 Author      :
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 200

char path[MAX] = "./User.txt\0";

typedef struct {
	int year;
	int month;
	int day;
}Date;

typedef struct {
	int userID;
	char first[MAX];
	char last[MAX];
	int account;
	char psw[MAX];
	char type;
}UserInfo;

typedef struct {
	int bookID;
	char bookName[MAX];
	char author[MAX];
	char user[MAX];
	Date borrow;
	Date due;
}Book;



int main(void) {
	//printf("%s",path);
	int userNum = 0;
	int numUser = 0;
	char buffer[MAX];
	FILE *user = fopen(path, "r");
	if( !user){
		printf("Failed to open user file\n");
		exit(1);
	}
	while(!feof(user)){
		fgets(buffer, MAX, user);
		puts(buffer);
	}
	return EXIT_SUCCESS;
}

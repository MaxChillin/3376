/*
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[256];
char* tokens;

int main(int argc, char *argv[]){

	printf("Please Enter A Command or String of Commands: ");
	fgets(input, 256, stdin);	
	printf("You Entered %s\n", input);

	tokens = strtok(input, " ");
	printf("Command: %s\n", tokens);
	tokens = strtok(NULL, " ");

	while(tokens != NULL){

		if(strcmp(tokens, "|") == 0){
			printf("Pipe\n");
			tokens = strtok(NULL, " ");
			printf("Command: %s\n", tokens);
			tokens = strtok(NULL, " ");
			continue;
		}// end of Pipe if statement

		if(strcmp(tokens, "<") == 0 || strcmp(tokens, ">") == 0 || strcmp(tokens, ">>") == 0){
			printf("File Redirection: %s\n", tokens);
			tokens = strtok(NULL, " ");
			printf("File: %s\n", tokens);
			tokens = strtok(NULL, " ");
			continue;
		}// end of < > >> if statement

		if(tokens[0] == '-'){
			printf("Options: %s\n", tokens);
			tokens = strtok(NULL, " ");
			continue;
		}// end of Options if statement

		if(tokens[0] == '.'){
			printf("Arguments: %s\n", tokens);
			tokens = strtok(NULL, " ");
			continue;
		}// end of Arguments if statement

	}// end of  while loop

	return EXIT_SUCCESS;

}// end of main function

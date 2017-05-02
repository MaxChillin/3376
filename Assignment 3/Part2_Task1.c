/*
 * Part2_Task1.c
 *
 *  Created on: Nov 14, 2016
 *      Author: Jeremy Pierce
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){

	char input[256];
	char *tokens, *commands;
//	int index;

	printf("Please Enter A Command: ");
	fgets(input, 256, stdin);

	printf("Original Input is %s", input);
	commands = strtok(input, "|");
//	tokens = strtok(input, " ");
	printf("Second Input is %s\n", input);

	while(commands != NULL){

		printf("Command is %s\n", commands);






		commands = strtok(NULL, "|");
	}









	exit(0);


	while(tokens != NULL){

		if(strcmp(tokens, "|") == 0){
			int pipefd[2];
			pid_t cpid;
			char buf;

			if (argc != 2) {
				fprintf(stderr, "Usage: %s <string>\n", argv[0]);
				exit(EXIT_FAILURE);
			}

			if (pipe(pipefd) == -1) {
				perror("pipe");
				exit(EXIT_FAILURE);
			}

			cpid = fork();
			if (cpid == -1) {
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (cpid == 0) {    /* Child reads from pipe */
				close(pipefd[1]);          /* Close unused write end */

				while (read(pipefd[0], &buf, 1) > 0)
					write(STDOUT_FILENO, &buf, 1);

				write(STDOUT_FILENO, "\n", 1);
				close(pipefd[0]);
				_exit(EXIT_SUCCESS);

			} else {            /* Parent writes argv[1] to pipe */
				close(pipefd[0]);          /* Close unused read end */
				write(pipefd[1], argv[1], strlen(argv[1]));
				close(pipefd[1]);          /* Reader will see EOF */
				wait(NULL);                /* Wait for child */
				exit(EXIT_SUCCESS);
			}

		}// end of pipe

		if(strcmp(tokens, "<") == 0){

		}// read from file

		if(strcmp(tokens, ">") == 0){

		}// writer to file

		if(strcmp(tokens, ">>") == 0){

		}// append to a file

		if(tokens[0] == '.' || tokens[0] == '/' || tokens[0] == '~'){

		}//directory argument

		tokens = strtok(NULL, " ");

	}// end of while(tokens != NULL)

	return EXIT_SUCCESS;
}

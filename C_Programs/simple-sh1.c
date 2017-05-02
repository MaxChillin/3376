/*
 * sh1.c: sample version 1 of a UNIX command shell/interpreter.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char line[256];
char prompt[] = "SimpleShell: Enter command or exit % ";
char* tokens;

    /* spit out the prompt */
printf("%s", prompt );

    /* Try getting input. If error or EOF, exit */
while( fgets(line, sizeof line, stdin) != NULL ){
	/* fgets leaves '\n' in input buffer. ditch it */
	line[strlen(line)-1] = '\0';

	if(strcmp(line,"exit") == 0){
		break;
	} else {

		tokens = strtok(line, " ");
		
		char newLine[256] = "";

		while (tokens != NULL){
	
			if (strcmp(tokens,"list") == 0) {
				strcat(newLine, "ls");
				tokens = strtok(NULL, " ");
				//continue;
			}else if (strcmp(tokens,"print") == 0) {
				strcat(newLine, "cat");
				tokens = strtok(NULL, " ");
				//continue;
			}else{
				strcat(newLine, tokens);
//				strcat(newLine, " ");
				tokens = strtok(NULL, " ");
			}
			strcat(newLine, " ");
		}

		//printf("The new line is %s\n", newLine);
     		system( newLine );
	}

	printf("%s", prompt );
}

return EXIT_SUCCESS;
}

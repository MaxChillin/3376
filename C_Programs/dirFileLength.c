#include <sys/types.h>
#include <dirent.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype
void dirFilenameLength(char *dirName);

// Variable Declaration
unsigned char isFile = 0x8;
char input[256];
int maxFilenameLength = 0;
char longestFilename[256];

// Main Function
int main(){

	printf("Hello, please enter the name of a directory: ");
	scanf("%s", input);
	dirFilenameLength(input);

return EXIT_SUCCESS;
}// end of main function

// This function take a directory name and prints the filename with the longest name
void dirFilenameLength(char *dirName){
	
	DIR *dp;
	struct dirent *dirp;
	
	if ((dp = opendir(dirName)) == NULL ) { 
    	fprintf(stderr, "I'm Sorry, '%s' is not a valid directory name\n", dirName); 
    	exit(EXIT_FAILURE);
	}// end of if statement 
         
	while ((dirp = readdir(dp)) != NULL ){ 
		if(dirp->d_type == isFile){
			if(maxFilenameLength < strlen(dirp->d_name)){
				strcpy(longestFilename, "");
				maxFilenameLength = strlen(dirp->d_name);
				strcat(longestFilename, dirp->d_name);
			}
		}// end of if statement
	}// end of while loop
        	printf("The longest filename is \"%s\" with %2d characters\n", longestFilename, maxFilenameLength);
 
    closedir(dp);

}// end of dirFilenameLength function
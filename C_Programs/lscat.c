 #include <sys/types.h>
 #include <dirent.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>

 #define BUFFSIZE 32768

 int main(int argc, char **argv) {

	DIR *dp; 
	struct dirent *dirp;
	
	int n, fileNumber;
	char buf[BUFFSIZE];

	if (argc != 2) {
		fprintf(stderr, "usage: %s dir_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}// end of directory error if statement

	if ((dp = opendir(argv[1])) == NULL ) {
		fprintf(stderr, "can't open '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}// end of open failure if statement

	while ((dirp = readdir(dp)) != NULL ){

		if(dirp->d_name[strlen(dirp->d_name)-2] == '.' && dirp->d_name[strlen(dirp->d_name)-1] == 'c'){
			
			printf("\n\n\n\n***********************\n");
			printf("\t%s\n", dirp->d_name);
			printf("***********************\n\n");
			fileNumber = open(dirp->d_name, O_RDONLY);

		        while ((n = read(fileNumber, buf, BUFFSIZE)) > 0) {

		                if (write(STDOUT_FILENO, buf, n) != n) {
		                        fprintf(stderr, "write error\n");
		                        exit(EXIT_FAILURE);

		                }// end of write error if statememt

		        }// end of while loop

		        if (n < 0) {
		                fprintf(stderr, "read error\n");
		                exit(EXIT_FAILURE);

		        }// end of (n < 0) if statement

		}// end of '.' 'c' if statement

	}// end of while loop

	closedir(dp);
	return EXIT_SUCCESS;

}// end of main 

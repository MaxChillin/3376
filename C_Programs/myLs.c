/* 
 * simple-ls.c
 * Extremely low-power ls clone.
 * ./simple-ls .
 */

 #include <sys/types.h>
 #include <dirent.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main(int argc, char **argv) {

	DIR *dp;
	struct dirent *dirp;

	if (argc != 2) {
		fprintf(stderr, "usage: %s dir_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((dp = opendir(argv[1])) == NULL ) {
		fprintf(stderr, "can't open '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while ((dirp = readdir(dp)) != NULL ){
		if(dirp->d_name[0] == '.')
			continue;
		if(dirp->d_name[strlen(dirp->d_name)-2] == '.' && dirp->d_name[strlen(dirp->d_name)-1] == 'c')
			printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	return EXIT_SUCCESS;
}

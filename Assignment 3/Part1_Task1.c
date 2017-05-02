/*
 * Part1_Task1.c
 *
 *  Created on: Nov 13, 2016
 *      Author: Jeremy Pierce
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv[]){

	mkdir("./dir1", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	mkdir("./dir1/dir11", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	mkdir("./dir1/dir12", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	mkdir("./dir1/dir11/dir111", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	mkdir("./dir1/dir12/dir121", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

	creat("./dir1/c100.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/c200.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/c300.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/p010.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/p020.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/p030.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/t001.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/t002.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/t003.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/f100", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/f200", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

	creat("./dir1/dir11/c100.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/c200.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/c300.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/p010.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/p020.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/p030.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/t001.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/t002.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/t003.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/f100", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir11/f200", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

	creat("./dir1/dir12/c100.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/c200.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/c300.c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/p010.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/p020.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/p030.pl", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/t001.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/t002.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/t003.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/f100", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	creat("./dir1/dir12/f200", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);


	return EXIT_SUCCESS;
}

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>

 #define BUFFSIZE 32768

 int main(int argc, char **argv) {
 	int testNumber, pizzaNumber, test2Number;
	
	pizzaNumber = open("pizza.txt", O_RDONLY);
	testNumber = open("test.txt", O_RDONLY);
	test2Number = open("test2.txt", O_RDONLY);

	printf("Pizza Number is %d\n", pizzaNumber);
	printf("Test Number is %d\n", testNumber);
	printf("Test2 Number is %d\n", test2Number);


//	while ((n = read(fileNumber, buf, BUFFSIZE)) > 0) {
//		if (write(STDOUT_FILENO, buf, n) != n) {
//			fprintf(stderr, "write error\n");
//			exit(1);
//		}
//	}

//	if (n < 0) {
//		fprintf(stderr, "read error\n");
//		exit(1);
//	}

	return(EXIT_SUCCESS);
}

#include "apue.h"
#include <fcntl.h>

char	buf1[16384];
char	buf2[] = "ABCDEFGHIJ";

int main(void) {
	
	int fd, i;

	for(i = 0;i < 16384; i++){
		strcat(buf1, "a");

	}
	
	if ((fd = creat("file.nohole", FILE_MODE)) < 0)
		printf("creat error");
	
	if (write(fd, buf1, 16384) != 16384)
		printf("buf1 write error");	/* offset now = 10 */

	if (write(fd, buf2, 10) != 10)
		printf("buf2 write error");	/* offset now = 16394 */
	
	exit(EXIT_SUCCESS);
}

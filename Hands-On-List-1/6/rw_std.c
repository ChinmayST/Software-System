

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	char message[20];
	read(STDOUT_FILENO,message,20);
	write(STDIN_FILENO,message,20);

	return 0;
}

/*
Output :
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab6$ gcc -o rw_std rw_std.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab6$ ./rw_std
Test input STDIN
Test input STDIN
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab6$ 

*/

/*
============================================================================
Name : 5.c
Author : Chinmay Tavarej
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
Date: 11th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	for(int i=0; i<5; ++i){
		char filename[20];
		snprintf(filename,sizeof(filename),"file%d.txt",i);
		int fd=open(filename,O_CREAT,O_WRONLY,O_TRUNC,0644);
		if(fd<0){
			perror("open");
			return 1;
		}
		close(fd);
	}
	for(;;){
		sleep(1);
	}

	return 0;
}

/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/5 nt$ ls
 infi_prog_desc   infi_prog_desc.c  'Pasted image.png'
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/5 nt$ ./infi_prog_desc &
[1] 21009
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/5 nt$ ls -l proc/21009/fd
ls: cannot access 'proc/21009/fd': No such file or directory
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/5 nt$ ls -l /proc/21009/fd
total 0
lrwx------ 1 iiitb iiitb 64 Aug 31 22:19 0 -> /dev/pts/1
lrwx------ 1 iiitb iiitb 64 Aug 31 22:19 1 -> /dev/pts/1
lrwx------ 1 iiitb iiitb 64 Aug 31 22:19 2 -> /dev/pts/1
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/5 nt$ 

*/

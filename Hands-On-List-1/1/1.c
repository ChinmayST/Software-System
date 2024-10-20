/*
====================================================================================================================================================================================
Name : 1.c
Author : Chinmay Tavarej
Description :
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

Date : 8th August 2024
===================================================================================================================================================================================

*/




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

void soft_link()
{
    char a[100],b[100];
    printf("Enter the directory for File 1 : ");
    scanf("%s",a);
    printf("Enter the directory for File 2 : ");
    scanf("%s",b);
    int sl = symlink(a,b);
    if(sl == 0)
      printf("Soft Link is sucessful \n");
    else
      printf("Soft Link is failed \n");
}

void hard_link()
{
    char a[100],b[100];
    printf("Enter the directory for File 1 : ");
    scanf("%s",a);
    printf("Enter the directory for File 2 : ");
    scanf("%s",b);
    int sl = link(a,b);
    if(sl == 0)
      printf("Hard Link is sucessful \n");
    else
      printf("Hard Link is failed \n");
}

void fifo_file()
{
    char a[100];
    printf("Enter the name of the File : ");
    scanf("%s",a);
    
    int sl = mkfifo(a,S_IFIFO);
    if(sl == 0)
      printf("fifo file is sucessful \n");
    else
      printf("fifo file is failed \n");
}

int main()
{
	    printf("1. create soft link \n");
	    printf("2. create hard link \n");
	    printf("3. create fifo file \n");
	    
	    do
	    {
	        printf("Enter your choice : ");
	        int choice;
	        scanf("%d",&choice);
	        if(choice == 1)
	              soft_link();
    
	        else if(choice == 2)
	              hard_link();
	              
	        else if(choice == 3)
	              fifo_file();
	    
	        else
	        {
	          printf("Invalid choice \n");
	          break;
	        }
	        
	        
	    }while(1);
	    return 0;
}


/*

===================================================================================================================================================================================
output:
(i) shell command:

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ touch test1.txt
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ ln -s test1.txt 888
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ ln test1.txt 444
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ mkfifo 555
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ ls
 1.c      888          'hard link using syscall.png'   test2.txt
 1_main   a.out         main.c                         test3.txt
 444      hardlink     'softlink using syscall.png'
 555      hard_link.c   test1.txt
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ 



(ii) System call: 


 gcc -o 1_main 1.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/hands on lab1/lab1$ ./1_main
1. create soft link 
2. create hard link 
3. create fifo file 
Enter your choice : 1
Enter the directory for File 1 : one.txt
Enter the directory for File 2 : 123
Soft Link is sucessful 
Enter your choice : 2
Enter the directory for File 1 : one.txt
Enter the directory for File 2 : 456
Hard Link is sucessful 
Enter your choice : 3
Enter the name of the File : 789
fifo file is sucessful 
Enter your choice : 4
Invalid choice 

=================================================================================================================================================================================

*/

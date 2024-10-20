/*
====================================================================================================================================================================================
Name : 18.c
Author : Chinmay Tavarej
Description :
Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

Date : 28th August 2024
===================================================================================================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

struct database{
int roll;
int marks;
}db;



int main()
{

    printf("There are total 3 records in the file \n select the record to perform read or write operation on 1 or 2 or 3 \n");
    int n;
    scanf("%d",&n);
    if(n > 3 || n <1)
    {
        printf("Invalid input so terminating program \n");
        exit(0);
    }
    
    printf("Perform read or write 1 . read or 2. write By default goes to read \n");
    int t;
    scanf("%d",&t);
    struct flock locking;
  if(t == 2)
  locking.l_type = F_WRLCK;
  else
  locking.l_type = F_RDLCK;
  
  
    
    int fd = open("record.txt",O_RDWR);
  if(fd == -1)
  {
    perror("File cannot be opened \n");
    exit(0);
  }
  
  
  
  locking.l_whence = SEEK_SET;
  locking.l_start = sizeof(db)*(n-1);
  locking.l_len = sizeof(db);
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    perror("Cannot obtained the lock for writing so exiting the program \n");
    exit(0);
  }
  
  if(t == 2)
  {
      printf("Enter the roll number : ");
      scanf("%d",&(db.roll));
      printf("Enter the marks : ");
      scanf("%d",&(db.marks));
      lseek(fd,sizeof(db)*(n-1),SEEK_SET);
      write(fd,&db,sizeof(db));
      
  }
  else
  {
      lseek(fd,sizeof(db)*(n-1),SEEK_SET);
      if(read(fd,&db,sizeof(db)))
      {
            printf("%d  %d\n",db.roll, db.marks);
      }
      else
      {
          perror("Error while reading file \n");
          
      }
  }
  
  
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  printf("Contents of the records after modification : \n");
  
  
  fd = open("record.txt",O_RDONLY);
  locking.l_type = F_RDLCK;
  
  stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    perror("Cannot obtained the lock  for reading file so exiting the program  \n");
    exit(0);
  }
  
  
  while(read(fd,&db,sizeof(db)))
  {
    printf("%d  %d \n",db.roll,db.marks);
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  
  
    
}


/*
====================================================================================================================================================================================
Output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab18$ gcc initial.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab18$ ./a.out
1  50 
2  60 
3  70 
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab18$ gcc 18.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab18$ ./a.out
There are total 3 records in the file 
 select the record to perform read or write operation on 1 or 2 or 3 
1
Perform read or write 1 . read or 2. write By default goes to read 
1
1  50
Contents of the records after modification : 
1  50 
2  60 
3  70 
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab18$ 






====================================================================================================================================================================================
*/

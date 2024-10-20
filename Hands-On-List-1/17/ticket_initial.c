/*
====================================================================================================================================================================================
Name : ticket_initial.c
Author : Chinmay Tavarej
Description :
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date : 24th August 2024
===================================================================================================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
struct database{
int comp;
int ticket;
}db;



int main()
{
  //struct database an;
 
  
  //printf("%d  --> %d \n",as.a,as.b);
  struct flock locking;
  locking.l_type = F_WRLCK;
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  
  int fd = open("ticket_count.txt",O_RDWR);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    return 0;
  }
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock so exiting the program \n");
    return 0;
  }
  
  
  for(int i=0;i<5;i++)
 { 
  db.comp = i+1;
  db.ticket = 120;
  write(fd,&db,sizeof(db));
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
   

  return 0;
}



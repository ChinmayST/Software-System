#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
struct database{
  int comp;
  int ticket;
}db;

struct passenger{
  char name[100];
  int comp;
  int ticket;
}p1;


int main()
{
  //struct database an;
 

  //printf("%d  --> %d \n",as.a,as.b);
  int fd = open("ticket_count.txt",O_RDWR);
  struct database as;
   while(read(fd,&as,sizeof(as)))
   {
       printf("%d  --> %d \n",as.comp,as.ticket);
   }
  
    fd = open("ticket_details.txt",O_RDWR);
    
    while(read(fd,&p1,sizeof(p1)))
    {
      printf("%s    %d   %d \n",p1.name,p1.comp,p1.ticket);
    }

  return 0;
}

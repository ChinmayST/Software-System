#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-Rl", (char *)NULL);
    perror("execlp failed");
    return 1;
}

/*

iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ gcc 27b.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ ./a.out
.:
total 312
-rw-rw-r-- 1 iiitb iiitb   1476 Aug 31 22:37  27a.c
-rw-rw-r-- 1 iiitb iiitb    648 Aug 30 00:32  27b.c
-rw-rw-r-- 1 iiitb iiitb   1317 Aug 30 00:32  27c.c
-rw-rw-r-- 1 iiitb iiitb   1450 Aug 30 00:32  27d.c
-rw-rw-r-- 1 iiitb iiitb   1517 Aug 30 00:32  27e.c
-rwxrwxr-x 1 iiitb iiitb  16000 Aug 31 22:37  a.out
-rw-rw-r-- 1 iiitb iiitb 282119 Aug 30 00:32 'Pasted image.png'




*/


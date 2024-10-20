/*
============================================================================
Name : 13.c
Author : Chinmay Tavarej
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 10th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
    fd_set input_set;
    struct timeval wait_interval;
    int status_code;

    FD_ZERO(&input_set);
    FD_SET(STDIN_FILENO, &input_set);

    wait_interval.tv_sec = 10;
    wait_interval.tv_usec = 0;

    status_code = select(STDIN_FILENO + 1, &input_set, NULL, NULL, &wait_interval);

    if (status_code == -1) {
        perror("Error with select");
        exit(EXIT_FAILURE);
    } else if (status_code == 0) {
        printf("No input detected within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &input_set)) {
            printf("Input detected within 10 seconds.\n");
        }
    }

    return 0;
}


/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/13 what$ gcc 13.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/13 what$ ./a.out
No data available within 10 seconds.  (didn't typed in 10 sec)


*/

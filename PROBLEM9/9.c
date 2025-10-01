/*
===================================================================================================================
Name: 9.c
Author: VIVEK JOSHI
Description:-Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Step 1: Ignoring SIGINT (Ctrl+C)...\n");
    signal(SIGINT, SIG_IGN);  // Ignore SIGINT

    // Give user some time to test ignoring Ctrl+C
    for (int i = 5; i > 0; i--) {
        printf("You cannot terminate with Ctrl+C right now (%d seconds left)\n", i);
        sleep(1);
    }

    printf("\nStep 2: Resetting SIGINT to default action.\n");
    signal(SIGINT, SIG_DFL);  // Restore default action

    // Now if user presses Ctrl+C, program will terminate
    printf("Now try pressing Ctrl+C (it will terminate the program).\n");

    // Keep the program running to test default behavior
    while (1) {
        sleep(1);
    }

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM9$ g++ 9.c -o 9

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM9$ ./9

Step 1: Ignoring SIGINT (Ctrl+C)...
You cannot terminate with Ctrl+C right now (5 seconds left)
You cannot terminate with Ctrl+C right now (4 seconds left)
You cannot terminate with Ctrl+C right now (3 seconds left)
^CYou cannot terminate with Ctrl+C right now (2 seconds left)
^CYou cannot terminate with Ctrl+C right now (1 seconds left)

Step 2: Resetting SIGINT to default action.
Now try pressing Ctrl+C (it will terminate the program).
^C



===================================================================================================================
*/


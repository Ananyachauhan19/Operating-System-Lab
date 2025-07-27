#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1 = fork();

    if (child1 == 0) {
        printf("First Child (PID %d): Sleeping...\n", getpid());
        sleep(5);
        printf("First Child: Parent PID after sleep = %d (Should be 1 or reaper if orphaned)\n", getppid());
        exit(0);
    } else {
        pid_t child2 = fork();
        if (child2 == 0) {
            printf("Second Child (PID %d): Exiting immediately.\n", getpid());
            exit(0);
        } else {
            printf("Parent (PID %d): Exiting before first child completes.\n", getpid());
            exit(0); 
        }
    }

    return 0;
}

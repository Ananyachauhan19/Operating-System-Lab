#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter Size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum_even = 0, sum_odd = 0;

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                sum_odd += arr[i];
            }
        }       
        wait(NULL);
        printf("Sum of odd numbers: %d\n", sum_odd);
    } 
    else if (pid > 0) {
        printf("Parent process (PID: %d)\n", getpid());
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                sum_even += arr[i];
            }
        }
        printf("Sum of even numbers: %d\n", sum_even);
        exit(0);
    } 
    else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}

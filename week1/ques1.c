/*
System calls are the way programs request services from the operating system (OS). These are low-level functions provided by the kernel, such as:
-> Creating files
-> Reading/writing data
-> Creating or killing processes
-> Allocating memory
They act as a bridge between user space (where your programs run) and kernel space (where the OS core functions).
Example system calls:
->read() – to read from a file or input
->write() – to write data
->open(), close() – to handle files
->fork() – to create a new process

What is fork()?
fork() is a system call in UNIX/Linux used to create a new process.
When a process calls fork():
A new child process is created.
It is an exact copy of the parent process (same code, same data).
Both processes (parent and child) run independently from that point onward.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t p_id;
    p_id = fork();
    if (p_id < 0)
    {
        printf("fork failed");
        return 1;
    }
    else if (p_id == 0)
    {
        printf("i am child process.... \n");
    }
    else
    {
        printf("i am parent process ...\n");
    }
    return 0;
}
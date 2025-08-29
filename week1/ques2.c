/*
----->  fork() : Used to create new processes. The new process consists of a copy of the address
 space of the original process. System call returns zero in child process while it returns child
 process id in parent process.
-----> getpid() : Each process is identified by its id value. This function is used to get the id value of
 a particular process.
-----> getppid() : Used to get particular process parent's id value

-----> pid_t stands for Process ID Type.
It's a data type defined in POSIX systems (like Linux/UNIX) and is used to store process IDs (PIDs) — which are integers that uniquely identify processes in the system.

-----> Advantage of using pid_t instead of int
1. Portability - > On some systems, pid_t might not be an int. Using pid_t makes your code portable across UNIX-like systems.
2. Readability - > It clearly signals that this variable holds a process ID, not just any integer.
3. Standard Practise - > All system calls like fork(), waitpid(), getpid() use pid_t, so matching types is good practice.
 */

 #include<stdio.h> 
 #include<unistd.h> 
 #include<sys/types.h> 
 
 int main(){ 
    pid_t id; 
    id=fork(); 
    if(id<0){ 
        printf("sorry fork failed. \n"); 
        return 1; 
    } 
    else if(id==0){ 
        printf("child process is running .....\n"); 
        printf("child p_id  : %d \n",getpid()); 
        printf("parent p_id(child) : %d \n ",getppid()); 
    } 
    else{ 
        printf("parent process is running ....\n"); 
        printf("parent p_id : %d\n",getpid()); 
        printf("child id(parent) : %d \n",id); 
    } 
return 0; 
 
} 
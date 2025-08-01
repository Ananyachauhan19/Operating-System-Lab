#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(){
   pid_t pid=fork();
      if(pid>0){
       wait(NULL);
       printf("%d\n",getpid());
       printf("Parent Process complete\n");
   }
   else if(pid==0){
       printf("%d\n",getpid());
       printf("Child Process\n");
       execlp("ls","ls","-l",(char*)NULL);
       exit(0);
   }
   else{
      printf("Process not created\n");
   }
   printf("ORPHAN PROBLEM\n");
   pid_t x=fork();
   if(x>0){
       wait(NULL);
       printf("%d\n",getpid());
       printf("Parent Process complete\n");
   }
   else if(x==0){
       printf("%d\n",getpid());
       printf("Child Process\n");
       execlp("ls","ls","-l",(char*)NULL);
       exit(0);
   }
   else{
      printf("Process not created\n");
   }
return 0;
}

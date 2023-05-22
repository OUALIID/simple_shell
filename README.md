# README BASIC SHELL
*BASIC SHELL FUNCTIONS*
	#getpid()
		Takes in parametres void and returns the pid of the child of the current process.
			```c
			#include <stdio.h>
			#include <unistd.h>
			/*The unistd.h is the liberary in which the function getpid() exists*/
			int main()
			{
			pid_t pid;
			pid = getpid();
			printf("%d", pid);
			return (0);
			}```
		**-G**etpid  function returns a value of type pid_t, which is integer type. This type is defined in sys/types.h, but since it is alse defined in unistd.h then only called that liberary.
		**-I**s a system call, which means that it communicates with the kernel to retrieve the child's process ID.
		**-T**he PID is assigned to the process by the operating system when the process is created and remains constant throughout the lifetime of the process.
		**-T**he PID value is usually positive, with values greater than 1. The value of 0 is reserved for the scheduler process, while -1 is used to indicate an error, and -2 is used to indicate that the PID is not known (for example, if the process has terminated and its PID has been reassigned to a new process).
	#getppid()
		Takes in parametres void and returns the ID of the parent process of the current process.
			```c
			#include <stdio.h>
			#include <unistd.h>
			/*The unistd.h is the liberary in which the function getppid() exists*/
			int main()
			{
				pid_t ppid;
				ppid = getppid();
				printf("%d", ppid);
				return (0);
			}```
		**-G**etppid  function returns a value of type pid_t, which is integer type. This type is defined in sys/types.h, but since it is alse defined in unistd.h then only called that liberary.
		**-I**s a system call, which means that it communicates with the kernel to retrieve the parent process ID.
		**-I**f the calling process has no parent (e.g. because it has been orphaned), `getppid()` returns 1, which is the PID of the `init` process, the first process started by the system during the boot process.
	#exit ()
		It is used to terminate a program and return the status to the parent process.
			```c
			#include <stdio.h>
			#include <stdlib.h>
			int main()
			{
				int n;
				n = 2;
				if (n > 0)
				{
					printf("%d is higher than zero\n", n);
					exit(0);
				}
				return (0);
			}```
		**-I**t takes a single integer argument, which is the status code to be returned to the parent process. A status code of 0 indicates successful termination of the program, while a non-zero value indicates an error.
		**-W**hen exit is called it flushes all open output streams, closing all open input streams, closing all open file descriptors, removing temporary files created by the program, and returning control to the parent process.
	#getline()
		It is used to read a line from the input stream, it keeps reading untill it reaches the end of the line, stores the line in a buffer. The length of the line is stored in a variable of type int intialized to zero.
			```c
			#include <stdio.h>
			int main()
			{
				char *line = NULL;
				int len = 0;
				int val;
				val = getline(&line, &len, stdin);
				if(val == -1)
				{
					printf("Error");
					exit(1);
				}
				printf("Your line is : %s", line);
				return (0);
			}```
		**-D**efined in the stdio.h liberary.
		**-T**he return value of getline can be eather -1 in case of failing, or the length of the string in case of succeding.
		**-T**he memory of the buffer is dynamicly attocated by the function, and the function keeps on storing untill it encounters a null character.
	#execve()
		It unable us to execute another program specified in arguments. This function replaces the program that it's running from with in with the given program in parametres.
			```c
			#include <stdio.h>
			int main()
			{
				int val;
				char args[] = {"/bin/ls", "-l", "/usr/", NULL};
				printf("Before execve! ");
				val = execve(args[0], agrs, NULL);
				if (val == -1)
				{
					printf("Error");
					exit(1);
				}
				printf("After the execve");
				return (0);
			}```
		**-T**he args table conatains the arguments that we will execute, in this example we will be executing the following command : *ls -l /usr/*
		**-T**he arguments of execve should be the name of the program to be executed, a commands like *ls* for example, or another c program *./example*, what ever it was, it's name is in the argv[0].
		**RESULT** The  program when compiled and executed will display Before execve! , then display the result of the command *ls -l /usr/*, and the last line will not be printed since the program will be replaced by the execution of the command.
	#fork()
		It unables us to create another sub-process that we consider the child of our current process. A block of code after the fork will be executed in the sub-process and not the original process.
			```c
			#include <stdio.h>
			#include <unistd.h>
			int main()
			{
				int val;
				val = fork();
				if (val == 0)
					printf("CHILD process\n");
				else if (val > 0)
					printf("PARENT process\n");
				else
				{
					printf("FAILED\n");
					exit(1);
				}
				return (0);
			}```
		**-W**hen fork() is called, a copy of the original process is created, it is an exact copy but with a different PID.
		**-T**he resulted process is the child of the original prcess, while the original is called the parent of the resulted process.
		**-T**he fork return value is different in the parent process and the child process. In the parent process the fork returns the PID of the child process, but in the child process the fork returns zero.
		**I**n case of failure fork returns a negative value. 
	#wait()
	#waitpid()
	#perror()
	#strtok()
	


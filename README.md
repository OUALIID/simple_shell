<head>
</head>
<body>
    <h1>README BASIC SHELL</h1>
    <h3>BASIC SHELL FUNCTIONS</h3>
    <menu>
        <h4>getpid()</h4>
        <p>Takes in parametres void and returns the pid of the child of the current process.</p>
        <pre>
            <code>
			    #include <stdio.h>
			    #include <unistd.h>
			    /*The unistd.h is the liberary in which the function getpid() exists*/
			    int main()
			    {
			        pid_t pid;
			        pid = getpid();
			        printf("%d", pid);
			        return (0);
			    }
            </code>
        </pre>
        <ul>
		<li><b>Getpid</b> function returns a value of type pid_t, which is integer type. This type is defined in sys/types.h, but since it is alse defined in unistd.h then only called that liberary.</li>
		<li>Is a system call, which means that it communicates with the kernel to retrieve the child's process ID.</li>
		<li>The PID is assigned to the process by the operating system when the process is created and remains constant throughout the lifetime of the process.</li>
		<li>The PID value is usually positive, with values greater than 1. The value of 0 is reserved for the scheduler process, while -1 is used to indicate an error, and -2 is used to indicate that the PID is not known (for example, if the process has terminated and its PID has been reassigned to a new process).</li>
        </ul>
    </menu>
</body>

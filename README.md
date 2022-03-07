<h1 align=center>
	<b>Minishell</b>
</h1>

![VM](https://static.vecteezy.com/ti/vetor-gratis/p1/658484-concha-de-caracol-em-branco-gr%C3%A1tis-vetor.jpg)

<h2 align=center> Table of Contents </h2>
<h3><b>
	<a href="#extfun">1. External Functs.</br></a>
</b></h3>
	<span> • </span><a href="#apirest">1.1 What is API REST?</br></a>
<h3><b>
	<a href="#cli">2. Command line interface</br></a>
</b></h3>
	<span> • </span><a href="#Overview">2.1 Overview</br></a>
<h3><b>
	<a href="#mysql">3. Mysql</br></a>
</b></h3>
	<span> • </span><a href="#install1">3.1 Install & Configuring </br></a>
<h3><b>
	<a href="#docker">4. Docker</br></a>
</b></h3>
	<span> • </span><a href="#install2">4.1 Installing & Configuring</br></a>
<h3><b>

<h3><b>
	<a href="#cloud">5. Cloud database</br></a>
</b></h3>
	<span> • </span><a href="#install3">5.1 Installing & Configuring</br></a>
<h3><b>

<h3><b>
	<a href="#ref">References</br></a>
</b></h3>

<h2 align=center id="extfun">
	<b>External Functs.</b>
</h2>

<table>
    <thead>
        <tr>
            <th colspan=3><h4>The C Standard Library <a href="https://man7.org/linux/man-pages/man0/unistd.h.0p.html">&lt;unistd.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th colspan=3><h4>File control options <a href="https://man7.org/linux/man-pages/man0/fcntl.h.0p.html">&lt;fcntl.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Function</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man3/open.3p.html">open</a></td>
            <td>Used to Open the file for reading, writing or both</td>
        </tr>
		<tr>
            <td><a href="https://man7.org/linux/man-pages/man2/close.2.html">close</a></td>
            <td>Tells the operating system you are done with a file descriptor and Close the file which pointed by fd. </td>
        </tr>
		<tr>
            <td><a href="https://man7.org/linux/man-pages/man2/read.2.html">read</a></td>
            <td>From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area indicated by buf. A successful read() updates the access time for the file.</td>
        </tr>
		<tr>
            <td><a href="https://man7.org/linux/man-pages/man2/write.2.html">write</a></td>
            <td>Writes cnt bytes from buf to the file or socket associated with fd. cnt should not be greater than INT_MAX (defined in the limits.h header file). If cnt is zero, write() simply returns 0 without attempting any other action.</td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/unlink.2.html">unlink </a></td>
            <td>Delete a name and possibly the file it refers </td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/fork.2.html">fork </a></td>
            <td>Create a child process </td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/dup.2.html">dup </a></td>
            <td>The dup() system call creates a copy of a file descriptor. </td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/dup.2.html">dup2 </a></td>
            <td>The dup2() system call is similar to dup() but the basic difference between them is that instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user. </td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/pipe.2.html">pipe </a></td>
            <td>Conceptually, a pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process.  </td>
        </tr>
        <tr>
            <td><a href="https://man7.org/linux/man-pages/man2/execve.2.html">execve </a></td>
            <td>Executes the program referred to by pathname.  This causes the program that is currently being run by the calling
       process to be replaced with a new program, with newly initialized stack, heap, and (initialized  and  uninitialized)  data
       segments. </td>
        </tr>
        <tr>
            <td><a href=""> </a></td>
            <td> </td>
        </tr>
        <tr>
            <td><a href=""> </a></td>
            <td> </td>
        </tr>
    </tbody>
</table>

<h2 align=center id="ref">
	<b>References</b>
</h2>

 - Minishell: geeks for geeks.

<p><a href="https://www.geeksforgeeks.org/making-linux-shell-c/"><i><b>Making your own Linux Shell in C</b></i></a></p>

 - External Functs. (implementation examples)

<p><a href="https://linuxhint.com/getcwd-function-c/"><i><b>C GetCWD Function Usage</b></i></a></p>
<p><a href="https://www.tutorialspoint.com/c_standard_library/c_function_getenv.htm"><i><b>C library function - getenv()</b></i></a></p>

<p><a href="https://www.geeksforgeeks.org/pipe-system-call/?ref=gcse"><i><b>pipe() System call</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/dup-dup2-linux-system-call/?ref=gcse"><i><b>dup() and dup2() Linux system call</b></i></a></p>
<p><a href="https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-unlink-remove-directory-entry"><i><b>unlink() — Remove a directory entry</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/wait-system-call-c/#:~:text=Syntax%20in%20c%20language%3A&text=pid_t%20wait(int%20*stat_loc)%3B,of%20the%20terminated%20child%20process."><i><b>Wait System Call in C</b></i></a></p>
<p><a href="https://iq.opengenus.org/chdir-fchdir-getcwd-in-c/#:~:text=The%20getcwd()%20function%20places,of%20getcwd()%20is%20undefined."><i><b>chdir(), fchdir() and getcwd() in C</b></i></a></p>
<p><a href="https://linuxhint.com/getcwd-function-c/"><i><b>C GetCWD Function Usage</b></i></a></p>
<p><a href="https://stackoverflow.com/questions/23085076/readline-readline-h-file-not-found"><i><b>'readline/readline.h' file not found</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/"><i><b>Input-output system calls in C | Create, Open, Close, Read, Write</b></i></a></p>
<p><a href="https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm"><i><b>C library function - perror()</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/fork-system-call/?ref=gcse"><i><b>fork() in C</b></i></a></p>
<p><a href="https://man7.org/linux/man-pages/man2/execve.2.html"><i><b>execve - execute program (example at the end of the manual)</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/exec-family-of-functions-in-c/?ref=gcse"><i><b>exec family of functions in C</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/"><i><b>chdir() in C language with Examples</b></i></a></p>
<p><a href="https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/isatty.html"><i><b>C Tutorial: isatty</b></i></a></p>
<p><a href="https://www.geeksforgeeks.org/error-handling-c-programs/#:~:text=Global%20Variable%20errno%3A%20When%20a,in%20the%20header%20file%20errno."><i><b>Error Handling in C programs</b></i></a></p>
<p><a href="https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm"><i><b>C library function - signal()</b></i></a></p>

 - External Functs. (videos)
<p><a href="https://www.youtube.com/playlist?list=PLjGsWcIYtLBp4qQz70Dx1YWiFNQ-uGw9I"><i><b>pipex (my playlist)</b></i></a></p>

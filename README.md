*This project has been created as part of the 42 curriculum by sbeldjao*

---

# Get Next Line
### Reading a line from a file descriptor is way too tedious.

---

## Description
Learn how to read content line by line—whether it comes from a file, standard input, or even a network connection. This activity introduces a fundamental function that will be essential for handling input streams in your future programming projects.

## Instructions
*Prototype* `char	*get_next_line(int fd)`  
Repeated calls (e.g., using a loop) to **get_next_line()** function should let you read the text file pointed to by the file descriptor, one line at a time.  
When there is nothing else to read or if an error occurred, it return NULL.  
By default, the buffer size is set to 42 bytes, but it is possible to add the option to your compiler call `-D BUFFER_SIZE=n` to modify the buffer size value.  

## Resources
Thanks to my pear **Wissem B.** for his many contributions.  
C Programming Language - 2nd Edition (Brian W.Kernighan / Dennis M.Ritchie).  
https://www.learn-c.org  
https://koor.fr/C/cstdarg/va_arg.wp  
IA : ChatGPT to learn me how to use and understand **valgrind**.

## Technical choices
*General operation of the algorithm.*  

- After the initialization of the variables and the buffer, the first two reads of the data stream allow for handling access problems (file permissions, for example) and **file descriptor** errors.  
- Next, a loop will feed the buffer until a newline character (**\n**) or the end of the data stream is detected.  
- For the buffer, a struct is used to store the data from the **read** operation, the size of this data in bytes, and the position of the next newline character (**\n**).  
- A linked list is used to store the buffer segments between two newline characters (**\n**). This linked list will then be iterated over to generate the string returned by the **get_next_line** function.  

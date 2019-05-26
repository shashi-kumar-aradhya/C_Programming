Basic Concepts

1. A named pipe works much like a regular pipe, but does have some noticeable differences.

   a. Named pipes exist as a device special file in the file system.
   b. Processes of different ancestry can share data through a named pipe.
   c. When all I/O is done by sharing processes, the named pipe remains in the file system for later use. 

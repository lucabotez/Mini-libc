Copyright @lucabotez

# Mini-libc

## Overview
**Mini-libc** is a lightweight **standard C library replacement** for Linux, built from scratch using **low-level system calls**. Designed as a **freestanding implementation**, it provides core functionalities like **string management, memory allocation, and POSIX file I/O**, without relying on an external libc (e.g., glibc). This project helps explore the **syscall interface, memory management, and fundamental C library functions**.

## Objectives
- Understand the **structure and functionalities** of the standard C library.
- Learn how **system calls** work in Linux.
- Gain in-depth knowledge of **string and memory management functions**.
- Implement **low-level I/O operations** using direct system calls.

## Features
- **String manipulation functions** (e.g., `strcpy()`, `strcat()`, `strlen()`, etc.).
- **Memory allocation support** (`malloc()`, `free()`, `mmap()`, etc.).
- **POSIX-compliant file I/O functions** (`open()`, `close()`, `lseek()`, etc.).
- **Sleep functions** (`sleep()`, `nanosleep()`).
- **Freestanding implementation**, avoiding external libc dependencies.

## Implementation Details
### **1. String Handling (`string.h`)**
The following **string functions** are implemented:
- `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`
- `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
- `memcpy()`, `memset()`, `memmove()`, `memcmp()`

### **2. File I/O (`unistd.h`, `sys/fcntl.h`, `sys/stat.h`)**
The following **file operations** are supported:
- `open()`, `close()`, `lseek()`
- `stat()`, `fstat()`, `truncate()`, `ftruncate()`

### **3. Memory Management (`stdlib.h`, `sys/mman.h`)**
The following **memory allocation functions** are implemented:
- `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`
- `mmap()`, `mremap()`, `munmap()`

### **4. I/O Functions (`stdio.h`)**
- `puts()` – A minimal implementation of standard output printing.

### **5. Sleep Functions (`time.h`)**
- `sleep()`, `nanosleep()` – Implemented using direct system calls.

### **6. Error Handling (`errno.h`)**
- Implements the `errno` variable to track errors from system calls.

## Notes
- The implementation is **targeted for x86_64 Linux systems**.
- System calls are invoked via `syscall()` (`src/syscall.c`).

/*
===================================================================================================================
Name: 19.c.c
Author: VIVEK JOSHI
Description:-Create a FIFO file by
c. use strace command to find out, which command (mknod or mkfifo) is better.

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "my fifo using mkfifo";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("FIFO file '%s' created successfully.\n", fifo_name);
    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ g++ 19.a.c -o 19a

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ g++ 19.b.c -o 19b

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ strace ./19a

execve("./19a", ["./19a"], 0x7ffd1a3ec860 /* 48 vars */) = 0
brk(NULL)                               = 0x5db6a85d1000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d7a7b17d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=72427, ...}) = 0
mmap(NULL, 72427, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7d7a7b16b000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7d7a7ae00000
mmap(0x7d7a7ae28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7d7a7ae28000
mmap(0x7d7a7afb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7d7a7afb0000
mmap(0x7d7a7afff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7d7a7afff000
mmap(0x7d7a7b005000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7d7a7b005000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d7a7b168000
arch_prctl(ARCH_SET_FS, 0x7d7a7b168740) = 0
set_tid_address(0x7d7a7b168a10)         = 15848
set_robust_list(0x7d7a7b168a20, 24)     = 0
rseq(0x7d7a7b169060, 0x20, 0, 0x53053053) = 0
mprotect(0x7d7a7afff000, 16384, PROT_READ) = 0
mprotect(0x5db67e23e000, 4096, PROT_READ) = 0
mprotect(0x7d7a7b1bb000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7d7a7b16b000, 72427)           = 0
mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666) = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
getrandom("\x58\x92\x1f\xef\x6b\xcf\x6c\x93", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x5db6a85d1000
brk(0x5db6a85f2000)                     = 0x5db6a85f2000
write(1, "FIFO file 'myfifo' created succe"..., 41FIFO file 'myfifo' created successfully.
) = 41
exit_group(0)                           = ?
+++ exited with 0 +++


vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ strace ./19b

execve("./19b", ["./19b"], 0x7ffc7e279680 /* 48 vars */) = 0
brk(NULL)                               = 0x5ebfefe68000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x787d3657b000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=72427, ...}) = 0
mmap(NULL, 72427, PROT_READ, MAP_PRIVATE, 3, 0) = 0x787d36569000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x787d36200000
mmap(0x787d36228000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x787d36228000
mmap(0x787d363b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x787d363b0000
mmap(0x787d363ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x787d363ff000
mmap(0x787d36405000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x787d36405000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x787d36566000
arch_prctl(ARCH_SET_FS, 0x787d36566740) = 0
set_tid_address(0x787d36566a10)         = 15854
set_robust_list(0x787d36566a20, 24)     = 0
rseq(0x787d36567060, 0x20, 0, 0x53053053) = 0
mprotect(0x787d363ff000, 16384, PROT_READ) = 0
mprotect(0x5ebfbe264000, 4096, PROT_READ) = 0
mprotect(0x787d365b9000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x787d36569000, 72427)           = 0
mknodat(AT_FDCWD, "my fifo using mkfifo", S_IFIFO|0666) = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
getrandom("\xcb\x3d\xef\x80\xd5\x3a\xa8\x7e", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x5ebfefe68000
brk(0x5ebfefe89000)                     = 0x5ebfefe89000
write(1, "FIFO file 'my fifo using mkfifo'"..., 55FIFO file 'my fifo using mkfifo' created successfully.
) = 55
exit_group(0)                           = ?
+++ exited with 0 +++



mkfifo() is simpler: it’s just one wrapper call. having less parameters
===================================================================================================================
*/


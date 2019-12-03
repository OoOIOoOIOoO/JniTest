/***************************************************************************************************
libc API hook function list:
    long syscall(long __number, ...);
    int creat(const char* pathname, mode_t mode)
    int open(const char* pathname, int flags, ...)
    int __open_2(const char* pathname, int flags)
    int openat(int fd, const char *pathname, int flags, ...)
    DIR* opendir(const char*);
    int __openat_2(int fd, const char* pathname, int flags)
    int access(const char* path, int mode)
    int faccessat(int dirfd, const char* pathname, int mode, int flags)
    int chown(const char* path, uid_t uid, gid_t gid)
    int lchown(const char* path, uid_t uid, gid_t gid)
    int fchownat(int __dirfd, const char* __path, uid_t __owner, gid_t __group, int __flags);
    int chmod(const char* path, mode_t mode)
    int fchmodat(int dirfd, const char* pathname, mode_t mode, int flags)
    int system(const char *string);
    int execv(const char* __path, char* const* __argv);
    int execvp(const char* __file, char* const* __argv);
    int execvpe(const char* __file, char* const* __argv, char* const* __envp) __INTRODUCED_IN(21);
    int execl(const char* __path, const char* __arg0, ...) __attribute__((__sentinel__));
    int execlp(const char* __file, const char* __arg0, ...) __attribute__((__sentinel__));
    int execle(const char* __path, const char* __arg0, ... /,  char* const* __envp /)__attribute__((__sentinel__(1)));
    int execve(const char* __file, char* const* __argv, char* const* __envp);
    ssize_t getxattr(const char* path, const char* name, void* value, size_t size) __INTRODUCED_IN(16);
    ssize_t lgetxattr(const char* path, const char* name, void* value, size_t size) __INTRODUCED_IN(16);
    int setxattr(const char* path, const char* name, const void* value, size_t size, int flags) __INTRODUCED_IN(16)
    int lsetxattr(const char* path, const char* name, const void* value, size_t size, int flags) __INTRODUCED_IN(16);
    ssize_t llistxattr(const char* path, char* list, size_t size) __INTRODUCED_IN(16);
    ssize_t listxattr(const char* path, char* list, size_t size) __INTRODUCED_IN(16);
    int removexattr(const char* path, const char* name) __INTRODUCED_IN(16);
    int lremovexattr(const char* path, const char* name) __INTRODUCED_IN(16);
    int link(const char* __oldpath, const char* __newpath);
    int linkat(int __olddirfd, const char* __oldpath, int __newdirfd, const char* __newpath, int __flags) __INTRODUCED_IN(21);
    int remove(const char *);
    int rmdir(const char *pathname);
    int unlink(const char* __path);
    int unlinkat(int __dirfd, const char* __path, int __flags);
    int lstat(const char*, struct stat*);
    int lstat64(const char*, struct stat64*) __INTRODUCED_IN(21);
    int stat(const char*, struct stat*);
    int stat64(const char*, struct stat64*) __INTRODUCED_IN(21);
    int fstatat(int, const char*, struct stat*, int);
    int fstatat64(int, const char*, struct stat64*, int) __INTRODUCED_IN(21);
    int mkdir(const char*, mode_t);
    int mkdirat(int, const char*, mode_t);
    int mkfifo(const char*, mode_t) __INTRODUCED_IN(21);
    int mkfifoat(int, const char*, mode_t) __INTRODUCED_IN(23);
    int mknod(const char*, mode_t, dev_t);
    int mknodat(int, const char*, mode_t, dev_t) __INTRODUCED_IN(21);
    char * realpath(const char *path, char *resolved) __overloadable __RENAME_CLANG(realpath);
    ssize_t readlink(const char* __path, char* __buf, size_t __bufsiz) __overloadable __RENAME_CLANG(readlink);
    ssize_t readlinkat(int __dirfd, const char* __path, char* __buf, size_t __bufsiz) __INTRODUCED_IN(21) __overloadable __RENAME_CLANG(readlinkat);
    char* getcwd(char* buf, size_t size)
    int __getcwd(char* buf, size_t size);
    int rename(const char *oldpath, const char *newpath);
    int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
    int statvfs(const char* __restrict _Nonnull, struct statvfs* __restrict _Nonnull) __INTRODUCED_IN(19);
    int statvfs64(const char* __restrict _Nonnull, struct statvfs64* __restrict _Nonnull) __INTRODUCED_IN(21);
    int statfs(const char* _Nonnull, struct statfs* _Nonnull);
    int statfs64(const char* _Nonnull, struct statfs64* _Nonnull) __INTRODUCED_IN(21);
    int __statfs64(const char*, size_t, struct statfs*);
    int symlink(const char* old_path, const char* new_path)
    int symlinkat(const char* __oldpath, int __newdirfd, const char* __newpath) __INTRODUCED_IN(21);
    long pathconf(const char* path, int name)
    int chdir(const char* __path)
    int rmdir(const char* __path);
    int chroot(const char* __path);
    int acct(const char* __filepath);
    int truncate(const char* __path, off_t __length) __RENAME(truncate64) __INTRODUCED_IN(21);
    int truncate64(const char* __path, off64_t __length) __INTRODUCED_IN(21);
    char* __getcwd_chk(char* buf, size_t len, size_t actual_size)
    char* mkdtemp(char*);
    FILE* fopen(const char* __restrict, const char* __restrict);
    FILE* fopen64(const char* __restrict, const char* __restrict) __INTRODUCED_IN(24);
    FILE* freopen(const char* __restrict, const char* __restrict, FILE* __restrict);
    FILE* freopen64(const char* __restrict, const char* __restrict, FILE* __restrict)
    int utimensat(int fd, const char* path, const struct timespec times[2], int flags) __INTRODUCED_IN(12);
****************************************************************************************************************/
/*
extern "C" int ___faccessat_my_1(int, const char*, int);
extern "C" int __openat_my_1(int, const char*, int, int);
extern "C" int fchownat_my_1(int __dirfd, const char* __path, uid_t __owner, gid_t __group, int __flags);
extern "C" int ___fchmodat_my_1(int dirfd, const char* pathname, mode_t mode, int flags);
extern "C" int execve_my_1(const char* file, char* const* argv, char* const* envp);
extern "C" ssize_t getxattr_my_1(const char* path, const char* name, void* value, size_t size) __INTRODUCED_IN(16);
extern "C" ssize_t lgetxattr_my_1(const char* path, const char* name, void* value, size_t size) __INTRODUCED_IN(16);
extern "C" int setxattr_my_1(const char* path, const char* name, const void* value, size_t size, int flags) __INTRODUCED_IN(16);
extern "C" int lsetxattr_my_1(const char* path, const char* name, const void* value, size_t size, int flags) __INTRODUCED_IN(16);
extern "C" ssize_t listxattr_my_1(const char* path, char* list, size_t size) __INTRODUCED_IN(16);
extern "C" ssize_t llistxattr_my_1(const char* path, char* list, size_t size) __INTRODUCED_IN(16);
extern "C" int removexattr_my_1(const char* path, const char* name) __INTRODUCED_IN(16);
extern "C" int lremovexattr_my_1(const char* path, const char* name) __INTRODUCED_IN(16);
extern "C" int linkat_my_1(int olddirfd, const char* oldpath, int newdirfd, const char* newpath, int flags) __INTRODUCED_IN(21);
extern "C" int unlinkat_my_1(int dirfd, const char* path, int flags);
extern "C" int fstatat64_my_1(int, const char*, struct stat64*, int) __INTRODUCED_IN(21);
extern "C" int fstatat_my_1(int, const char*, struct stat*, int);
extern "C" int mkdirat_my_1(int, const char*, mode_t);
extern "C" int mknodat_my_1(int, const char*, mode_t, dev_t) __INTRODUCED_IN(21);
extern "C" ssize_t readlinkat_my_1(int __dirfd, const char* __path, char* __buf, size_t __bufsiz) __INTRODUCED_IN(21) __overloadable __RENAME_CLANG(readlinkat_my_1);
extern "C" int __getcwd_my_1(char* buf, size_t size);
extern "C" int renameat_my_1(int, const char*, int, const char*);
extern "C" int symlinkat_my_1(const char* __oldpath, int __newdirfd, const char* __newpath) __INTRODUCED_IN(21);
extern "C" int chdir_my_1(const char* __path);
extern "C" int chroot_my_1(const char* __path);
extern "C" int truncate_my_1(const char* __path, off_t __length) __INTRODUCED_IN(21);
extern "C" int truncate64_my_1(const char* __path, off64_t __length) __INTRODUCED_IN(21);
extern "C" int acct_my_1(const char* __filepath);
extern "C" int utimensat_my_1(int fd, const char* path, const struct timespec times[2], int flags) __INTRODUCED_IN(12);
*/

/**
 *   todo list:
 *     1, java framework code hook services:   
 *           AccountManagerService
 *           ContentProvider
 *           UserManagerService
 *           NotificationManagerService
 *     以上是hook的具体service的组件,具体的hook方式参考VA的实现方式;
 *     
 *     2, 编写上述libc api test case:
 *        以上所有的API 的所有操作路径:　　inpath: /data/local/tmp/     hookpath: /data/local/tmp/hook/   outpath:/data/local/tmp/
 *        以上的hookpath对于开发人员是透明的; 
 *        demo 如下: 
 */
#include <stdio.h> 
#include <unistd.h> 
#include <stdarg.h> 
#include <sys/syscall.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <android/log.h>
#define IN_PATH "/data/local/tmp/"
#define OUT_PATH "/data/local/tmp/"
#define BUF_LINE 1024

/**
 * 1, 人工验证文件是否创建到了/data/local/tmp/hook/a.txt
 *    并且 OUT_PATH 目录下没有创建a.txt文件
 *
 * 2, 确认内容是否为hello world !
 *
 */
void creat_open_write_read_test(){
    char buf[BUF_LINE] = {};
    const char *cont  = "hello, world!\n";
	char *cont1;

    snprintf(buf, sizeof buf , "%s%s", IN_PATH, "a.txt");
	__android_log_print(ANDROID_LOG_VERBOSE,"test","path == %s \n",buf);
	int fd = remove(buf);
	fd = 0;
	__android_log_print(ANDROID_LOG_VERBOSE,"test","remove == %d \n",fd);
	fd = creat(buf, 0666);
	__android_log_print(ANDROID_LOG_VERBOSE,"test","creat == %d \n",fd);
    fd = 0;
	fd = open(buf, O_RDWR | O_CREAT);
	__android_log_print(ANDROID_LOG_VERBOSE,"test","open == %d \n",fd);
//    assert(fd > 2);
    write(fd, cont, strlen(cont));
	read(fd, cont1, strlen(cont));
	__android_log_print(ANDROID_LOG_VERBOSE,"test","read == %s \n",cont);
    close(fd);
}

void syscall_test(){
	char buf[BUF_LINE] = {};
	snprintf(buf, sizeof buf , "%s%s", IN_PATH, "a.txt");
//	int fd = syscall(SYS_open, buf,  O_RDONLY, 0644);
//	printf("syscall == %d \n",fd);
}

void openat_test(){
	char buf[BUF_LINE] = {};
	snprintf(buf, sizeof buf , "%s%s", IN_PATH, "a.txt");
	int fd = openat(1,buf, O_RDWR | O_CREAT,0644);
	__android_log_print(ANDROID_LOG_VERBOSE,"test","openat == %d \n",fd);
}

void opendir_test(){
	DIR *dir_ptr = opendir(IN_PATH);
	if(dir_ptr == NULL){
		__android_log_print(ANDROID_LOG_VERBOSE,"test","Ls: can not open %s \n",IN_PATH);
	} else {
		__android_log_print(ANDROID_LOG_VERBOSE,"test","Ls: can open %s \n",IN_PATH);
		closedir(dir_ptr);
	}
}

int mains(){
    creat_open_write_read_test();
    syscall_test();
	openat_test();
	opendir_test();
    return 0;
}


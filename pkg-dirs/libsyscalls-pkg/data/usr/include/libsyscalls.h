#ifndef LIBSYSCALL_H
#define LIBSYSCALL_H

#ifdef __cplusplus
extern "C" {
#endif

	long read(int fd, char *buf, long count);
	long write(int fd, char *buf, long count);
	int open(const char *pathname, int flags, ...);
	int close(int fd);

#ifdef __cplusplus
}
#endif

#endif

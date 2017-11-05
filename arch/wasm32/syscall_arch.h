#if 0
#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) 0, __SYSCALL_LL_E((x))

#define __SC_socket      1
#define __SC_bind        2
#define __SC_connect     3
#define __SC_listen      4
#define __SC_accept      5
#define __SC_getsockname 6
#define __SC_getpeername 7
#define __SC_socketpair  8
#define __SC_send        9
#define __SC_recv        10
#define __SC_sendto      11
#define __SC_recvfrom    12
#define __SC_shutdown    13
#define __SC_setsockopt  14
#define __SC_getsockopt  15
#define __SC_sendmsg     16
#define __SC_recvmsg     17
#define __SC_accept4     18
#define __SC_recvmmsg    19
#define __SC_sendmmsg    20

long __sst_locked_fileyscall0(long n);
long __syscall1(long n, long a);
long __syscall2(long n, long a, long b);
long __syscall3(long n, long a, long b, long c);
long __syscall4(long n, long a, long b, long c, long d);
long __syscall5(long n, long a, long b, long c, long d, long e);
long __syscall6(long n, long a, long b, long c, long d, long e, long f);

// HACK other architectures don't do this.
#include "../../src/internal/syscall.h"
#endif

#ifndef __SYSCALL__
#define __SYSCALL__
#if 0
inline long __syscall0(long n) { return 0; }
inline long __syscall1(long n, long a) { return 0; }
inline long __syscall2(long n, long a, long b) { return 0; }
inline long __syscall3(long n, long a, long b, long c) {  return 0; }
inline long __syscall4(long n, long a, long b, long c, long d) { return 0; }
inline long __syscall5(long n, long a, long b, long c, long d, long e) { return 0; }
inline long __syscall6(long n, long a, long b, long c, long d, long e, long f) { return 0; }
#endif
#endif

#include "stdlib.h"
int wasm_close_fd(int fd);
size_t wasm_write_fd(int fd, const void *pv, size_t cb);
long long wasm_llseek_fd(int fd, long long offset, int whence);

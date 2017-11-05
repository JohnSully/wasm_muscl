#include "stdio_impl.h"

off_t __stdio_seek(FILE *f, off_t off, int whence)
{
	off_t ret;
    ret = wasm_llseek_fd(f->fd, off, whence);
	return ret;
}

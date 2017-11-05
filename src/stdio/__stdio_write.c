#include "stdio_impl.h"
#include <sys/uio.h>

size_t __stdio_write(FILE *f, const unsigned char *buf, size_t len)
{
    while (f->wpos > f->wbase)
    {
        size_t cbBufferWritten = wasm_write_fd(f->fd, f->wbase, f->wpos - f->wbase);
        if (cbBufferWritten == 0)
        {
            f->wpos = f->wbase = f->wend = 0;
            f->flags |= F_ERR;
            return 0;
        }
        f->wbase += cbBufferWritten;
    }
    size_t lenT = len;
    while (lenT > 0)
    {
        size_t cbBufferWritten = wasm_write_fd(f->fd, buf, lenT);
        if (cbBufferWritten == 0)
        {
            f->wpos = f->wbase = f->wend = 0;
            f->flags |= F_ERR;
            return len - lenT;
        }
        lenT -= cbBufferWritten;
        buf += cbBufferWritten;
    }

    f->wend = f->buf + f->buf_size;
    f->wpos = f->wbase = f->buf;
    return len;
}

int raise(int sig)
{
    abort();
}

void __lock(volatile int *plock)
{
    // NOP - no threads, no locks
}

void __unlock(volatile int *plock)
{
    // NOP - no threads, no locks
}

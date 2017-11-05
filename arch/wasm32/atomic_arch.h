#include <stdlib.h>

#define a_barrier() // no threads, no barriers

#define a_cas(p, t, s) (abort(), s)

#define a_crash() abort()

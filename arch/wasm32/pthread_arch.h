static inline struct pthread *__pthread_self(void) { return NULL; }

#define TP_ADJ(p) (p)

#define CANCEL_REG_IP 16

#define MC_PC gregs[REG_EIP]



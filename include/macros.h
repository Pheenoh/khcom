#ifndef GUARD_MACROS_H
#define GUARD_MACROS_H

#define INCLUDE_ASM(path) asm(".include \"" path "\"")

#define ALIGN_ZERO(n) asm(".align " #n ", 0")

#define COMMON __attribute__((aligned(4)))

#endif /* GUARD_MACROS_H */

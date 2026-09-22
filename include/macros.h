#ifndef GUARD_MACROS_H
#define GUARD_MACROS_H

#define INCLUDE_ASM(path) asm(".include \"" path "\"")

#define COMMON __attribute__((aligned(4)))

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define EWRAM_COMMON(align) __attribute__((section(".ewram_common." STRINGIFY(__LINE__)), aligned(align))) = {0}
#define IWRAM_DATA(align) __attribute__((section(".iwram." STRINGIFY(__LINE__)), aligned(align))) = {0}
#define IWRAM_COMMON(align) __attribute__((section(".iwram_common." STRINGIFY(__LINE__)), aligned(align))) = {0}

#endif /* GUARD_MACROS_H */

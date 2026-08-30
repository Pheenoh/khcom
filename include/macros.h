#ifndef GUARD_MACROS_H
#define GUARD_MACROS_H

/* Pull a not-yet-decompiled function's asm into this TU. The path is
 * resolved against asm/<version>/nonmatchings via the assembler's -I. */
#define INCLUDE_ASM(path) asm(".include \"" path "\"")

#endif /* GUARD_MACROS_H */

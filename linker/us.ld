ENTRY(_start);

SECTIONS
{
    . = 0x8000000;

    .text :
    {
        build/us/asm/header.o(.text);
        build/us/asm/rom.o(.text);
    }

    /DISCARD/ : { *(*); }
}

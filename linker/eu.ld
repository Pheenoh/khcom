ENTRY(_start);

SECTIONS
{
    . = 0x8000000;

    .text :
    {
        build/eu/asm/header.o(.text);
        build/eu/asm/rom.o(.text);
    }

    /DISCARD/ : { *(*); }
}

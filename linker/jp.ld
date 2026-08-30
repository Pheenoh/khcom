ENTRY(_start);

SECTIONS
{
    . = 0x8000000;

    .text :
    {
        build/jp/asm/header.o(.text);
        build/jp/asm/rom.o(.text);
    }

    /DISCARD/ : { *(*); }
}

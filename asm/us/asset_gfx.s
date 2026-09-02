@ Graphics, maps and audio. BIOS LZ77 and RLE chunks.
@ ROM 0x0160000..0x1B00000 (26,869,760 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08160000
data_08160000:
	.incbin "roms/B8CE.gba", 0x160000, 0x19a0000

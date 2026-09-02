@ Dialogue and script text, UTF-16LE.
@ ROM 0x0140000..0x0160000 (131,072 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08140000
data_08140000:
	.incbin "roms/B8CE.gba", 0x140000, 0x20000

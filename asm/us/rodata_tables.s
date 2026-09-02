@ Binary lookup tables and zero-padded runs.
@ ROM 0x0121330..0x0126624 (21,236 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08121330
data_08121330:
	.incbin "roms/B8CE.gba", 0x121330, 0x52f4

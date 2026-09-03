@ Per-unit .data: the chkobj object lists.
@ ROM 0x1ECEB74..0x1ED8644 (39,632 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09ECEB74
data_09ECEB74:
	.incbin "roms/B8CE.gba", 0x1eceb74, 0x9ad0

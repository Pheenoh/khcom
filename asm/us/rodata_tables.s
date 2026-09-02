@ Trailing code and interworking veneers ahead of the first rodata.
@ ROM 0x0121330..0x01213DC (172 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08121330
data_08121330:
	.incbin "roms/B8CE.gba", 0x121330, 0xac

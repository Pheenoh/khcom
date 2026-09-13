@ High entropy, likely FMV video data.
@ ROM 0x1B00000..0x1D00000 (2,097,152 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09B00000
data_09B00000:
	.incbin "assets/us/09B00000-09D00000.bin"

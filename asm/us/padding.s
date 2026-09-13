@ 0xFF padding out to 32 MB.
@ ROM 0x1EFBFDC..0x2000000 (1,064,996 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09EFBFDC
data_09EFBFDC:
	.incbin "assets/us/09EFBFDC-0A000000.bin"

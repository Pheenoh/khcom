.syntax unified
	.text
	.align 2, 0
	.global SoftReset
	.thumb
	.thumb_func
	.type SoftReset, %function
SoftReset:
	.incbin "roms/B8CP.gba", 0x116b10, 0x18
.syntax divided

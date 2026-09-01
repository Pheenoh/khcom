.syntax unified
	.align 2, 0
	.global SoftReset
	.thumb
	.thumb_func
	.type SoftReset, %function
SoftReset:
	.incbin "roms/B8CJ.gba", 0x11806c, 0x18
.syntax divided

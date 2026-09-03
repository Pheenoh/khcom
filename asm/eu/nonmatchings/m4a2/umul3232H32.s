.syntax unified
	.text
	.align 2, 0
	.global umul3232H32
	.thumb
	.thumb_func
	.type umul3232H32, %function
umul3232H32:
	.incbin "roms/B8CP.gba", 0x11dc60, 0x10
.syntax divided

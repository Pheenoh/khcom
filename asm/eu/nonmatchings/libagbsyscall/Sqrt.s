.syntax unified
	.text
	.align 2, 0
	.global Sqrt
	.thumb
	.thumb_func
	.type Sqrt, %function
Sqrt:
	.incbin "roms/B8CP.gba", 0x116b28, 0x4
.syntax divided

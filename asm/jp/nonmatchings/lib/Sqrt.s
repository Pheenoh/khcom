.syntax unified
	.align 2, 0
	.global Sqrt
	.thumb
	.thumb_func
	.type Sqrt, %function
Sqrt:
	.incbin "roms/B8CJ.gba", 0x118084, 0xc
.syntax divided

.syntax unified
	.align 2, 0
	.global GetRandom
	.thumb
	.thumb_func
	.type GetRandom, %function
GetRandom:
	.incbin "roms/B8CJ.gba", 0x65a4, 0x58
.syntax divided

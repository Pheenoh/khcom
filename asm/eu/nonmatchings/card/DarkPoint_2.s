.syntax unified
	.text
	.align 2, 0
	.global DarkPoint_2
	.thumb
	.thumb_func
	.type DarkPoint_2, %function
DarkPoint_2:
	.incbin "roms/B8CP.gba", 0xa8114, 0x150
.syntax divided

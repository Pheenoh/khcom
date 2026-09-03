.syntax unified
	.text
	.align 2, 0
	.global DarkPoint_2
	.thumb
	.thumb_func
	.type DarkPoint_2, %function
DarkPoint_2:
	.incbin "roms/B8CJ.gba", 0xab160, 0x150
.syntax divided

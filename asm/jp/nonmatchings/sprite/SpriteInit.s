.syntax unified
	.align 2, 0
	.global SpriteInit
	.thumb
	.thumb_func
	.type SpriteInit, %function
SpriteInit:
	.incbin "roms/B8CJ.gba", 0x1d60, 0x3c
.syntax divided

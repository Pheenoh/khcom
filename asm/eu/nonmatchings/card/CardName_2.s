.syntax unified
	.text
	.align 2, 0
	.global CardName_2
	.thumb
	.thumb_func
	.type CardName_2, %function
CardName_2:
	.incbin "roms/B8CP.gba", 0x9d31c, 0x9c
.syntax divided

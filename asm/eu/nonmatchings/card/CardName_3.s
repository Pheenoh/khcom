.syntax unified
	.text
	.align 2, 0
	.global CardName_3
	.thumb
	.thumb_func
	.type CardName_3, %function
CardName_3:
	.incbin "roms/B8CP.gba", 0x9d3b8, 0x5c
.syntax divided

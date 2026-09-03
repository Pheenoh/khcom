.syntax unified
	.align 2, 0
	.global CardName_2
	.thumb
	.thumb_func
	.type CardName_2, %function
CardName_2:
	.incbin "roms/B8CJ.gba", 0x9cf40, 0x90
.syntax divided

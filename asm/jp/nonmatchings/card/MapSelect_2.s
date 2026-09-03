.syntax unified
	.text
	.align 2, 0
	.global MapSelect_2
	.thumb
	.thumb_func
	.type MapSelect_2, %function
MapSelect_2:
	.incbin "roms/B8CJ.gba", 0x930dc, 0x308
.syntax divided

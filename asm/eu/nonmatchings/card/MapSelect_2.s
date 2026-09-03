.syntax unified
	.text
	.align 2, 0
	.global MapSelect_2
	.thumb
	.thumb_func
	.type MapSelect_2, %function
MapSelect_2:
	.incbin "roms/B8CP.gba", 0x931f0, 0x314
.syntax divided

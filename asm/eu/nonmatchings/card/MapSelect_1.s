.syntax unified
	.text
	.align 2, 0
	.global MapSelect_1
	.thumb
	.thumb_func
	.type MapSelect_1, %function
MapSelect_1:
	.incbin "roms/B8CP.gba", 0x920d8, 0x150
.syntax divided

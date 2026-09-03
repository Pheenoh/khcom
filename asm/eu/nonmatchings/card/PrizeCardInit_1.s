.syntax unified
	.text
	.align 2, 0
	.global PrizeCardInit_1
	.thumb
	.thumb_func
	.type PrizeCardInit_1, %function
PrizeCardInit_1:
	.incbin "roms/B8CP.gba", 0x96a44, 0x27c
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global PrizeCardInit_Boss_1
	.thumb
	.thumb_func
	.type PrizeCardInit_Boss_1, %function
PrizeCardInit_Boss_1:
	.incbin "roms/B8CP.gba", 0x96cc0, 0x28c
.syntax divided

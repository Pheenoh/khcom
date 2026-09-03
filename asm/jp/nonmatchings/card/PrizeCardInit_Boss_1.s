.syntax unified
	.text
	.align 2, 0
	.global PrizeCardInit_Boss_1
	.thumb
	.thumb_func
	.type PrizeCardInit_Boss_1, %function
PrizeCardInit_Boss_1:
	.incbin "roms/B8CJ.gba", 0x96b2c, 0x28c
.syntax divided

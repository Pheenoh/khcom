.syntax unified
	.align 2, 0
	.global PrizeCardInit_1
	.thumb
	.thumb_func
	.type PrizeCardInit_1, %function
PrizeCardInit_1:
	.incbin "roms/B8CJ.gba", 0x968d0, 0x25c
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global PrizeBoss_1
	.thumb
	.thumb_func
	.type PrizeBoss_1, %function
PrizeBoss_1:
	.incbin "roms/B8CJ.gba", 0x99710, 0x184
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global WorldSel_Before_1
	.thumb
	.thumb_func
	.type WorldSel_Before_1, %function
WorldSel_Before_1:
	.incbin "roms/B8CJ.gba", 0xa567c, 0x14c
.syntax divided

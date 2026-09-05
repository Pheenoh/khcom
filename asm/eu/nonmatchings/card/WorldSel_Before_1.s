.syntax unified
	.text
	.align 2, 0
	.global WorldSel_Before_1
	.thumb
	.thumb_func
	.type WorldSel_Before_1, %function
WorldSel_Before_1:
	.incbin "roms/B8CP.gba", 0xa6114, 0x14c
.syntax divided

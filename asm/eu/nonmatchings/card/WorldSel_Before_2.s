.syntax unified
	.text
	.align 2, 0
	.global WorldSel_Before_2
	.thumb
	.thumb_func
	.type WorldSel_Before_2, %function
WorldSel_Before_2:
	.incbin "roms/B8CP.gba", 0xa6260, 0xf4
.syntax divided

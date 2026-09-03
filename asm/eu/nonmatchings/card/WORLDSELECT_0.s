.syntax unified
	.text
	.align 2, 0
	.global WORLDSELECT_0
	.thumb
	.thumb_func
	.type WORLDSELECT_0, %function
WORLDSELECT_0:
	.incbin "roms/B8CP.gba", 0x91b38, 0x94
.syntax divided

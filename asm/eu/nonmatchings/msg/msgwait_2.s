.syntax unified
	.text
	.align 2, 0
	.global msgwait_2
	.thumb
	.thumb_func
	.type msgwait_2, %function
msgwait_2:
	.incbin "roms/B8CP.gba", 0x73354, 0x88
.syntax divided

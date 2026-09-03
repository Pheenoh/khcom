.syntax unified
	.align 2, 0
	.global msgwait_2
	.thumb
	.thumb_func
	.type msgwait_2, %function
msgwait_2:
	.incbin "roms/B8CJ.gba", 0x73e10, 0x88
.syntax divided

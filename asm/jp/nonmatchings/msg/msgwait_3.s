.syntax unified
	.text
	.align 2, 0
	.global msgwait_3
	.thumb
	.thumb_func
	.type msgwait_3, %function
msgwait_3:
	.incbin "roms/B8CJ.gba", 0x73e98, 0x28
.syntax divided

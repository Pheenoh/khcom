.syntax unified
	.text
	.align 2, 0
	.global msgwait_yesno_2
	.thumb
	.thumb_func
	.type msgwait_yesno_2, %function
msgwait_yesno_2:
	.incbin "roms/B8CP.gba", 0x73724, 0x148
.syntax divided

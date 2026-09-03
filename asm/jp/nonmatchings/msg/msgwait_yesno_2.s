.syntax unified
	.text
	.align 2, 0
	.global msgwait_yesno_2
	.thumb
	.thumb_func
	.type msgwait_yesno_2, %function
msgwait_yesno_2:
	.incbin "roms/B8CJ.gba", 0x741d8, 0x148
.syntax divided

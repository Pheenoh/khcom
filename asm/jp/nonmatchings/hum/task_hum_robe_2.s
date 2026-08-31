.syntax unified
	.align 2, 0
	.global task_hum_robe_2
	.thumb
	.thumb_func
	.type task_hum_robe_2, %function
task_hum_robe_2:
	.incbin "roms/B8CJ.gba", 0x59dc4, 0xc
.syntax divided

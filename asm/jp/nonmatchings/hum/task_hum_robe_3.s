.syntax unified
	.align 2, 0
	.global task_hum_robe_3
	.thumb
	.thumb_func
	.type task_hum_robe_3, %function
task_hum_robe_3:
	.incbin "roms/B8CJ.gba", 0x59dd0, 0xc
.syntax divided

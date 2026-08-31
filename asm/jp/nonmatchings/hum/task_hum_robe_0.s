.syntax unified
	.align 2, 0
	.global task_hum_robe_0
	.thumb
	.thumb_func
	.type task_hum_robe_0, %function
task_hum_robe_0:
	.incbin "roms/B8CJ.gba", 0x59cc8, 0x38
.syntax divided

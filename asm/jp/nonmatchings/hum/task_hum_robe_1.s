.syntax unified
	.align 2, 0
	.global task_hum_robe_1
	.thumb
	.thumb_func
	.type task_hum_robe_1, %function
task_hum_robe_1:
	.incbin "roms/B8CJ.gba", 0x59d00, 0xc4
.syntax divided

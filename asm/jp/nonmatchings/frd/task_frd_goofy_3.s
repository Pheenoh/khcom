.syntax unified
	.align 2, 0
	.global task_frd_goofy_3
	.thumb
	.thumb_func
	.type task_frd_goofy_3, %function
task_frd_goofy_3:
	.incbin "roms/B8CJ.gba", 0x46e0c, 0x44
.syntax divided

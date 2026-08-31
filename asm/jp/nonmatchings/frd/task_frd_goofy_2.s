.syntax unified
	.align 2, 0
	.global task_frd_goofy_2
	.thumb
	.thumb_func
	.type task_frd_goofy_2, %function
task_frd_goofy_2:
	.incbin "roms/B8CJ.gba", 0x46cfc, 0x110
.syntax divided

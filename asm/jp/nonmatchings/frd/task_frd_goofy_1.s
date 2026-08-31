.syntax unified
	.align 2, 0
	.global task_frd_goofy_1
	.thumb
	.thumb_func
	.type task_frd_goofy_1, %function
task_frd_goofy_1:
	.incbin "roms/B8CJ.gba", 0x467bc, 0x540
.syntax divided

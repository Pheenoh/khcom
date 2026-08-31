.syntax unified
	.align 2, 0
	.global task_wlogo_mons_1
	.thumb
	.thumb_func
	.type task_wlogo_mons_1, %function
task_wlogo_mons_1:
	.incbin "roms/B8CJ.gba", 0xb496c, 0x1e0
.syntax divided

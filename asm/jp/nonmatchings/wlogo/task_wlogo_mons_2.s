.syntax unified
	.align 2, 0
	.global task_wlogo_mons_2
	.thumb
	.thumb_func
	.type task_wlogo_mons_2, %function
task_wlogo_mons_2:
	.incbin "roms/B8CJ.gba", 0xb4b4c, 0x34
.syntax divided

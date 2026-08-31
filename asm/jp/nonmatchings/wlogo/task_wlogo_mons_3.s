.syntax unified
	.align 2, 0
	.global task_wlogo_mons_3
	.thumb
	.thumb_func
	.type task_wlogo_mons_3, %function
task_wlogo_mons_3:
	.incbin "roms/B8CJ.gba", 0xb4b80, 0x18
.syntax divided

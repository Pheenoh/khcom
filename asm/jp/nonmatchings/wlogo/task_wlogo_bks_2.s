.syntax unified
	.align 2, 0
	.global task_wlogo_bks_2
	.thumb
	.thumb_func
	.type task_wlogo_bks_2, %function
task_wlogo_bks_2:
	.incbin "roms/B8CJ.gba", 0xb7cd0, 0x3c
.syntax divided

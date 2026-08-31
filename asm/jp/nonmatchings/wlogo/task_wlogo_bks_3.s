.syntax unified
	.align 2, 0
	.global task_wlogo_bks_3
	.thumb
	.thumb_func
	.type task_wlogo_bks_3, %function
task_wlogo_bks_3:
	.incbin "roms/B8CJ.gba", 0xb7d0c, 0x40
.syntax divided

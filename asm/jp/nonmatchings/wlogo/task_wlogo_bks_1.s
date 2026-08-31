.syntax unified
	.align 2, 0
	.global task_wlogo_bks_1
	.thumb
	.thumb_func
	.type task_wlogo_bks_1, %function
task_wlogo_bks_1:
	.incbin "roms/B8CJ.gba", 0xb79c0, 0x310
.syntax divided

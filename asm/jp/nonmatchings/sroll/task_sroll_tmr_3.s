.syntax unified
	.align 2, 0
	.global task_sroll_tmr_3
	.thumb
	.thumb_func
	.type task_sroll_tmr_3, %function
task_sroll_tmr_3:
	.incbin "roms/B8CJ.gba", 0x115500, 0x18
.syntax divided

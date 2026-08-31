.syntax unified
	.align 2, 0
	.global task_sroll_tmr_1
	.thumb
	.thumb_func
	.type task_sroll_tmr_1, %function
task_sroll_tmr_1:
	.incbin "roms/B8CJ.gba", 0x115350, 0x40
.syntax divided

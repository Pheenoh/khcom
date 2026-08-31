.syntax unified
	.align 2, 0
	.global task_sroll_tmr_0
	.thumb
	.thumb_func
	.type task_sroll_tmr_0, %function
task_sroll_tmr_0:
	.incbin "roms/B8CJ.gba", 0x115320, 0x30
.syntax divided

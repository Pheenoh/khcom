.syntax unified
	.text
	.align 2, 0
	.global task_sroll_tmr_2
	.thumb
	.thumb_func
	.type task_sroll_tmr_2, %function
task_sroll_tmr_2:
	.incbin "roms/B8CP.gba", 0x113e2c, 0x170
.syntax divided

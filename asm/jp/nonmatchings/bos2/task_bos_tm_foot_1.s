.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_foot_1
	.thumb
	.thumb_func
	.type task_bos_tm_foot_1, %function
task_bos_tm_foot_1:
	.incbin "roms/B8CJ.gba", 0xbac40, 0x418
.syntax divided

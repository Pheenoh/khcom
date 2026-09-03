.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_foot_0
	.thumb
	.thumb_func
	.type task_bos_tm_foot_0, %function
task_bos_tm_foot_0:
	.incbin "roms/B8CJ.gba", 0xba9dc, 0x264
.syntax divided

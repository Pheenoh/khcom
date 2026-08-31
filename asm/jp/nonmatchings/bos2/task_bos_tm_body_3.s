.syntax unified
	.align 2, 0
	.global task_bos_tm_body_3
	.thumb
	.thumb_func
	.type task_bos_tm_body_3, %function
task_bos_tm_body_3:
	.incbin "roms/B8CJ.gba", 0xba044, 0xfc
.syntax divided

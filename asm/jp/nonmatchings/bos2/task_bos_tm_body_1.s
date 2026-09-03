.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_body_1
	.thumb
	.thumb_func
	.type task_bos_tm_body_1, %function
task_bos_tm_body_1:
	.incbin "roms/B8CJ.gba", 0xb9944, 0x4c0
.syntax divided

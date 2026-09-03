.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_body_2
	.thumb
	.thumb_func
	.type task_bos_tm_body_2, %function
task_bos_tm_body_2:
	.incbin "roms/B8CP.gba", 0xb6054, 0x240
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_body_1
	.thumb
	.thumb_func
	.type task_bos_tm_body_1, %function
task_bos_tm_body_1:
	.incbin "roms/B8CP.gba", 0xb5b94, 0x4c0
.syntax divided

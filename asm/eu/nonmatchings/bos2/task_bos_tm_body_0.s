.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_body_0
	.thumb
	.thumb_func
	.type task_bos_tm_body_0, %function
task_bos_tm_body_0:
	.incbin "roms/B8CP.gba", 0xb5964, 0x230
.syntax divided

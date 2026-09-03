.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_body_0
	.thumb
	.thumb_func
	.type task_bos_tm_body_0, %function
task_bos_tm_body_0:
	.incbin "roms/B8CJ.gba", 0xb9714, 0x230
.syntax divided

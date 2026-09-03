.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_1
	.thumb
	.thumb_func
	.type task_bos_jf_1, %function
task_bos_jf_1:
	.incbin "roms/B8CP.gba", 0xb94d8, 0x290
.syntax divided

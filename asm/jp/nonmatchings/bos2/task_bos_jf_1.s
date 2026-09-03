.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_1
	.thumb
	.thumb_func
	.type task_bos_jf_1, %function
task_bos_jf_1:
	.incbin "roms/B8CJ.gba", 0xbd288, 0x290
.syntax divided

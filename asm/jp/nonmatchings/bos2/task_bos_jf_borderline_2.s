.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_borderline_2
	.thumb
	.thumb_func
	.type task_bos_jf_borderline_2, %function
task_bos_jf_borderline_2:
	.incbin "roms/B8CJ.gba", 0xc1670, 0x474
.syntax divided

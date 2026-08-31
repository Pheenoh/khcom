.syntax unified
	.align 2, 0
	.global task_bos_jf_borderline_1
	.thumb
	.thumb_func
	.type task_bos_jf_borderline_1, %function
task_bos_jf_borderline_1:
	.incbin "roms/B8CJ.gba", 0xc160c, 0x64
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_2
	.thumb
	.thumb_func
	.type task_bos_pc_flt_2, %function
task_bos_pc_flt_2:
	.incbin "roms/B8CJ.gba", 0x10beac, 0xc8
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_1
	.thumb
	.thumb_func
	.type task_bos_pc_flt_1, %function
task_bos_pc_flt_1:
	.incbin "roms/B8CJ.gba", 0x10be48, 0x64
.syntax divided

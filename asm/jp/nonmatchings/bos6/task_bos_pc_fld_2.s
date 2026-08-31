.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_2
	.thumb
	.thumb_func
	.type task_bos_pc_fld_2, %function
task_bos_pc_fld_2:
	.incbin "roms/B8CJ.gba", 0x10b778, 0xb0
.syntax divided

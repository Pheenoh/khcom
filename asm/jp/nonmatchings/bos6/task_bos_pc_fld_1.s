.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_1
	.thumb
	.thumb_func
	.type task_bos_pc_fld_1, %function
task_bos_pc_fld_1:
	.incbin "roms/B8CJ.gba", 0x10b654, 0x124
.syntax divided

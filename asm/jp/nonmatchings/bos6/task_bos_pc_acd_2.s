.syntax unified
	.align 2, 0
	.global task_bos_pc_acd_2
	.thumb
	.thumb_func
	.type task_bos_pc_acd_2, %function
task_bos_pc_acd_2:
	.incbin "roms/B8CJ.gba", 0x10c0b8, 0x260
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_pc_acd_1
	.thumb
	.thumb_func
	.type task_bos_pc_acd_1, %function
task_bos_pc_acd_1:
	.incbin "roms/B8CJ.gba", 0x10c01c, 0x9c
.syntax divided

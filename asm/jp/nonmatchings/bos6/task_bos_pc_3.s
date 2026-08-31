.syntax unified
	.align 2, 0
	.global task_bos_pc_3
	.thumb
	.thumb_func
	.type task_bos_pc_3, %function
task_bos_pc_3:
	.incbin "roms/B8CJ.gba", 0x10b378, 0x54
.syntax divided

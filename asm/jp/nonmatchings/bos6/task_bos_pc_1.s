.syntax unified
	.align 2, 0
	.global task_bos_pc_1
	.thumb
	.thumb_func
	.type task_bos_pc_1, %function
task_bos_pc_1:
	.incbin "roms/B8CJ.gba", 0x10b0fc, 0x268
.syntax divided

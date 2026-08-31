.syntax unified
	.align 2, 0
	.global task_poo_leaf_1
	.thumb
	.thumb_func
	.type task_poo_leaf_1, %function
task_poo_leaf_1:
	.incbin "roms/B8CJ.gba", 0xcf3b0, 0x78
.syntax divided

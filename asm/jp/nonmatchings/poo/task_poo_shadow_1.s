.syntax unified
	.align 2, 0
	.global task_poo_shadow_1
	.thumb
	.thumb_func
	.type task_poo_shadow_1, %function
task_poo_shadow_1:
	.incbin "roms/B8CJ.gba", 0xcbffc, 0xc
.syntax divided

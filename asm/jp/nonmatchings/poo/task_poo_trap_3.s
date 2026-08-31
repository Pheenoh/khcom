.syntax unified
	.align 2, 0
	.global task_poo_trap_3
	.thumb
	.thumb_func
	.type task_poo_trap_3, %function
task_poo_trap_3:
	.incbin "roms/B8CJ.gba", 0xcbd7c, 0xe0
.syntax divided

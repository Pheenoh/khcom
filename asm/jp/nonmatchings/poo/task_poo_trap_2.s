.syntax unified
	.align 2, 0
	.global task_poo_trap_2
	.thumb
	.thumb_func
	.type task_poo_trap_2, %function
task_poo_trap_2:
	.incbin "roms/B8CJ.gba", 0xcbcd4, 0xa8
.syntax divided

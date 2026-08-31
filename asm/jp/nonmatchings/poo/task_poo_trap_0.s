.syntax unified
	.align 2, 0
	.global task_poo_trap_0
	.thumb
	.thumb_func
	.type task_poo_trap_0, %function
task_poo_trap_0:
	.incbin "roms/B8CJ.gba", 0xcbc40, 0x50
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_poo_piglet_1
	.thumb
	.thumb_func
	.type task_poo_piglet_1, %function
task_poo_piglet_1:
	.incbin "roms/B8CP.gba", 0xca158, 0x24c
.syntax divided

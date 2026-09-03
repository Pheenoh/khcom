.syntax unified
	.text
	.align 2, 0
	.global task_poo_rabbit_1
	.thumb
	.thumb_func
	.type task_poo_rabbit_1, %function
task_poo_rabbit_1:
	.incbin "roms/B8CP.gba", 0xcabc4, 0x208
.syntax divided

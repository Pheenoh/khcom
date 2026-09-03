.syntax unified
	.text
	.align 2, 0
	.global task_poo_bee_1
	.thumb
	.thumb_func
	.type task_poo_bee_1, %function
task_poo_bee_1:
	.incbin "roms/B8CJ.gba", 0xd0b9c, 0x200
.syntax divided

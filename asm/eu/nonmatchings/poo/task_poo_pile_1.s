.syntax unified
	.text
	.align 2, 0
	.global task_poo_pile_1
	.thumb
	.thumb_func
	.type task_poo_pile_1, %function
task_poo_pile_1:
	.incbin "roms/B8CP.gba", 0xc9a88, 0x110
.syntax divided

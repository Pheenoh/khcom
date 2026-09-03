.syntax unified
	.text
	.align 2, 0
	.global task_poo_pile_1
	.thumb
	.thumb_func
	.type task_poo_pile_1, %function
task_poo_pile_1:
	.incbin "roms/B8CJ.gba", 0xcd34c, 0x110
.syntax divided

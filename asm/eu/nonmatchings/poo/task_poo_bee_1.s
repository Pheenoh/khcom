.syntax unified
	.text
	.align 2, 0
	.global task_poo_bee_1
	.thumb
	.thumb_func
	.type task_poo_bee_1, %function
task_poo_bee_1:
	.incbin "roms/B8CP.gba", 0xcd2d8, 0x200
.syntax divided

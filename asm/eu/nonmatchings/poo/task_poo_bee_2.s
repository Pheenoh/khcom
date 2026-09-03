.syntax unified
	.text
	.align 2, 0
	.global task_poo_bee_2
	.thumb
	.thumb_func
	.type task_poo_bee_2, %function
task_poo_bee_2:
	.incbin "roms/B8CP.gba", 0xcd4d8, 0x138
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_poo_pooh_2
	.thumb
	.thumb_func
	.type task_poo_pooh_2, %function
task_poo_pooh_2:
	.incbin "roms/B8CP.gba", 0xc6214, 0x2a4
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_poo_wagon_2
	.thumb
	.thumb_func
	.type task_poo_wagon_2, %function
task_poo_wagon_2:
	.incbin "roms/B8CJ.gba", 0xd04cc, 0x27c
.syntax divided

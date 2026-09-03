.syntax unified
	.text
	.align 2, 0
	.global task_poo_cabbage_2
	.thumb
	.thumb_func
	.type task_poo_cabbage_2, %function
task_poo_cabbage_2:
	.incbin "roms/B8CP.gba", 0xcdc90, 0x150
.syntax divided

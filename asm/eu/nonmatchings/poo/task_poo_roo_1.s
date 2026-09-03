.syntax unified
	.text
	.align 2, 0
	.global task_poo_roo_1
	.thumb
	.thumb_func
	.type task_poo_roo_1, %function
task_poo_roo_1:
	.incbin "roms/B8CP.gba", 0xcb6f4, 0x160
.syntax divided

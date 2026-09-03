.syntax unified
	.text
	.align 2, 0
	.global task_poo_trapballoon_1
	.thumb
	.thumb_func
	.type task_poo_trapballoon_1, %function
task_poo_trapballoon_1:
	.incbin "roms/B8CP.gba", 0xc8e74, 0x14c
.syntax divided

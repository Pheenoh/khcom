.syntax unified
	.text
	.align 2, 0
	.global task_lockon_2
	.thumb
	.thumb_func
	.type task_lockon_2, %function
task_lockon_2:
	.incbin "roms/B8CP.gba", 0x61968, 0x104
.syntax divided

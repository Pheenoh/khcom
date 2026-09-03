.syntax unified
	.text
	.align 2, 0
	.global task_lockon_1
	.thumb
	.thumb_func
	.type task_lockon_1, %function
task_lockon_1:
	.incbin "roms/B8CP.gba", 0x61778, 0x1f0
.syntax divided

.syntax unified
	.align 2, 0
	.global task_lockon_1
	.thumb
	.thumb_func
	.type task_lockon_1, %function
task_lockon_1:
	.incbin "roms/B8CJ.gba", 0x5f148, 0x1f0
.syntax divided

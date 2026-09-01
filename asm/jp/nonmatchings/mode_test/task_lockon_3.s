.syntax unified
	.align 2, 0
	.global task_lockon_3
	.thumb
	.thumb_func
	.type task_lockon_3, %function
task_lockon_3:
	.incbin "roms/B8CJ.gba", 0x5f440, 0x30
.syntax divided

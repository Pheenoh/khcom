.syntax unified
	.align 2, 0
	.global task_lockon_2
	.thumb
	.thumb_func
	.type task_lockon_2, %function
task_lockon_2:
	.incbin "roms/B8CJ.gba", 0x5f338, 0x108
.syntax divided

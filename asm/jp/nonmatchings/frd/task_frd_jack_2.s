.syntax unified
	.align 2, 0
	.global task_frd_jack_2
	.thumb
	.thumb_func
	.type task_frd_jack_2, %function
task_frd_jack_2:
	.incbin "roms/B8CJ.gba", 0x48594, 0x1bc
.syntax divided

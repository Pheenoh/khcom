.syntax unified
	.text
	.align 2, 0
	.global task_frd_jack_2
	.thumb
	.thumb_func
	.type task_frd_jack_2, %function
task_frd_jack_2:
	.incbin "roms/B8CP.gba", 0x4c9e0, 0x1bc
.syntax divided

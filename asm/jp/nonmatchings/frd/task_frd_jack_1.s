.syntax unified
	.text
	.align 2, 0
	.global task_frd_jack_1
	.thumb
	.thumb_func
	.type task_frd_jack_1, %function
task_frd_jack_1:
	.incbin "roms/B8CJ.gba", 0x476a0, 0xef4
.syntax divided

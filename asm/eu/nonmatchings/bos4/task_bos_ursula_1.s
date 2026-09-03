.syntax unified
	.text
	.align 2, 0
	.global task_bos_ursula_1
	.thumb
	.thumb_func
	.type task_bos_ursula_1, %function
task_bos_ursula_1:
	.incbin "roms/B8CP.gba", 0xd8c3c, 0x5d4
.syntax divided

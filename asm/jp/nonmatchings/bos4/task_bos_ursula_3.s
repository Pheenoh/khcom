.syntax unified
	.align 2, 0
	.global task_bos_ursula_3
	.thumb
	.thumb_func
	.type task_bos_ursula_3, %function
task_bos_ursula_3:
	.incbin "roms/B8CJ.gba", 0xdc504, 0x2c
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_ursula_2
	.thumb
	.thumb_func
	.type task_bos_ursula_2, %function
task_bos_ursula_2:
	.incbin "roms/B8CJ.gba", 0xdc474, 0x90
.syntax divided

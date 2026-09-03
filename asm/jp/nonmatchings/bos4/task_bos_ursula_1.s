.syntax unified
	.text
	.align 2, 0
	.global task_bos_ursula_1
	.thumb
	.thumb_func
	.type task_bos_ursula_1, %function
task_bos_ursula_1:
	.incbin "roms/B8CJ.gba", 0xdbea0, 0x5d4
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_ursula_thunder_1
	.thumb
	.thumb_func
	.type task_bos_ursula_thunder_1, %function
task_bos_ursula_thunder_1:
	.incbin "roms/B8CJ.gba", 0xdddc4, 0x30
.syntax divided

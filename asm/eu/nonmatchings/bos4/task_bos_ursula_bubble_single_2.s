.syntax unified
	.text
	.align 2, 0
	.global task_bos_ursula_bubble_single_2
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_single_2, %function
task_bos_ursula_bubble_single_2:
	.incbin "roms/B8CP.gba", 0xdaae4, 0x84
.syntax divided

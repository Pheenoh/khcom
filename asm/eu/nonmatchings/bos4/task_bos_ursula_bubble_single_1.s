.syntax unified
	.text
	.align 2, 0
	.global task_bos_ursula_bubble_single_1
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_single_1, %function
task_bos_ursula_bubble_single_1:
	.incbin "roms/B8CP.gba", 0xda918, 0x1cc
.syntax divided

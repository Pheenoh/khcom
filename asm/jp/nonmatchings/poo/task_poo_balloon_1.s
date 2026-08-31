.syntax unified
	.align 2, 0
	.global task_poo_balloon_1
	.thumb
	.thumb_func
	.type task_poo_balloon_1, %function
task_poo_balloon_1:
	.incbin "roms/B8CJ.gba", 0xcbf20, 0x4
.syntax divided

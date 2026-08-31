.syntax unified
	.align 2, 0
	.global task_poo_balloon_2
	.thumb
	.thumb_func
	.type task_poo_balloon_2, %function
task_poo_balloon_2:
	.incbin "roms/B8CJ.gba", 0xcbf24, 0x94
.syntax divided

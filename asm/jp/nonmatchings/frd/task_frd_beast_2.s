.syntax unified
	.align 2, 0
	.global task_frd_beast_2
	.thumb
	.thumb_func
	.type task_frd_beast_2, %function
task_frd_beast_2:
	.incbin "roms/B8CJ.gba", 0x49c78, 0x110
.syntax divided

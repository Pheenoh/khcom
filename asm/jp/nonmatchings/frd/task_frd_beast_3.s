.syntax unified
	.align 2, 0
	.global task_frd_beast_3
	.thumb
	.thumb_func
	.type task_frd_beast_3, %function
task_frd_beast_3:
	.incbin "roms/B8CJ.gba", 0x49d88, 0x44
.syntax divided

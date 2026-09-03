.syntax unified
	.text
	.align 2, 0
	.global task_frd_beast_0
	.thumb
	.thumb_func
	.type task_frd_beast_0, %function
task_frd_beast_0:
	.incbin "roms/B8CP.gba", 0x4dc7c, 0x1f4
.syntax divided

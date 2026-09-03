.syntax unified
	.text
	.align 2, 0
	.global task_bos_boogie_1
	.thumb
	.thumb_func
	.type task_bos_boogie_1, %function
task_bos_boogie_1:
	.incbin "roms/B8CJ.gba", 0xd926c, 0x6f0
.syntax divided

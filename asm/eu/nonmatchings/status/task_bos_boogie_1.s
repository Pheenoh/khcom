.syntax unified
	.text
	.align 2, 0
	.global task_bos_boogie_1
	.thumb
	.thumb_func
	.type task_bos_boogie_1, %function
task_bos_boogie_1:
	.incbin "roms/B8CP.gba", 0xd6000, 0x6ec
.syntax divided

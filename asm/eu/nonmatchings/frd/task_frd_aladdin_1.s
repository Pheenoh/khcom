.syntax unified
	.text
	.align 2, 0
	.global task_frd_aladdin_1
	.thumb
	.thumb_func
	.type task_frd_aladdin_1, %function
task_frd_aladdin_1:
	.incbin "roms/B8CP.gba", 0x4d770, 0x370
.syntax divided

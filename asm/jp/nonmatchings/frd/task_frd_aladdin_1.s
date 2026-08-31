.syntax unified
	.align 2, 0
	.global task_frd_aladdin_1
	.thumb
	.thumb_func
	.type task_frd_aladdin_1, %function
task_frd_aladdin_1:
	.incbin "roms/B8CJ.gba", 0x49324, 0x370
.syntax divided

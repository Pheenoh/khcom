.syntax unified
	.text
	.align 2, 0
	.global task_emy_02_1
	.thumb
	.thumb_func
	.type task_emy_02_1, %function
task_emy_02_1:
	.incbin "roms/B8CJ.gba", 0x37538, 0x1fc
.syntax divided

.syntax unified
	.align 2, 0
	.global task_allmap_pusha_1
	.thumb
	.thumb_func
	.type task_allmap_pusha_1, %function
task_allmap_pusha_1:
	.incbin "roms/B8CJ.gba", 0xd4cdc, 0x60
.syntax divided

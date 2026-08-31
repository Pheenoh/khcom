.syntax unified
	.align 2, 0
	.global task_allmap_pusha_3
	.thumb
	.thumb_func
	.type task_allmap_pusha_3, %function
task_allmap_pusha_3:
	.incbin "roms/B8CJ.gba", 0xd4dac, 0x24
.syntax divided

.syntax unified
	.align 2, 0
	.global task_allmap_pusha_2
	.thumb
	.thumb_func
	.type task_allmap_pusha_2, %function
task_allmap_pusha_2:
	.incbin "roms/B8CJ.gba", 0xd4d3c, 0x70
.syntax divided

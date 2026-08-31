.syntax unified
	.align 2, 0
	.global task_bos_dsd_circle_2
	.thumb
	.thumb_func
	.type task_bos_dsd_circle_2, %function
task_bos_dsd_circle_2:
	.incbin "roms/B8CJ.gba", 0xc49fc, 0x58
.syntax divided

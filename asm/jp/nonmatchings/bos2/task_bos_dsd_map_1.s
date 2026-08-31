.syntax unified
	.align 2, 0
	.global task_bos_dsd_map_1
	.thumb
	.thumb_func
	.type task_bos_dsd_map_1, %function
task_bos_dsd_map_1:
	.incbin "roms/B8CJ.gba", 0xc3f18, 0xc0
.syntax divided

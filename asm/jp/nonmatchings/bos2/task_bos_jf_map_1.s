.syntax unified
	.align 2, 0
	.global task_bos_jf_map_1
	.thumb
	.thumb_func
	.type task_bos_jf_map_1, %function
task_bos_jf_map_1:
	.incbin "roms/B8CJ.gba", 0xbda5c, 0x104
.syntax divided

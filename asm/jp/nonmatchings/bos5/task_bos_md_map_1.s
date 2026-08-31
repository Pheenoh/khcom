.syntax unified
	.align 2, 0
	.global task_bos_md_map_1
	.thumb
	.thumb_func
	.type task_bos_md_map_1, %function
task_bos_md_map_1:
	.incbin "roms/B8CJ.gba", 0xfcb50, 0xe4
.syntax divided

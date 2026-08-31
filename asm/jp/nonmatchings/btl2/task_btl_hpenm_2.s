.syntax unified
	.align 2, 0
	.global task_btl_hpenm_2
	.thumb
	.thumb_func
	.type task_btl_hpenm_2, %function
task_btl_hpenm_2:
	.incbin "roms/B8CJ.gba", 0x30038, 0x19c
.syntax divided

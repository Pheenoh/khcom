.syntax unified
	.align 2, 0
	.global task_btl_hpenm_3
	.thumb
	.thumb_func
	.type task_btl_hpenm_3, %function
task_btl_hpenm_3:
	.incbin "roms/B8CJ.gba", 0x301d4, 0x24
.syntax divided

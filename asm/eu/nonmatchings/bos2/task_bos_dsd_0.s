.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_0
	.thumb
	.thumb_func
	.type task_bos_dsd_0, %function
task_bos_dsd_0:
	.incbin "roms/B8CP.gba", 0xbde64, 0x354
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_dsd_ita_2
	.thumb
	.thumb_func
	.type task_bos_dsd_ita_2, %function
task_bos_dsd_ita_2:
	.incbin "roms/B8CJ.gba", 0xc41dc, 0x148
.syntax divided

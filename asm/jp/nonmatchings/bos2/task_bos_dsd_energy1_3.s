.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_3
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_3, %function
task_bos_dsd_energy1_3:
	.incbin "roms/B8CJ.gba", 0xc4d04, 0x160
.syntax divided

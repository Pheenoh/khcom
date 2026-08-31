.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_0
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_0, %function
task_bos_dsd_energy1_0:
	.incbin "roms/B8CJ.gba", 0xc4a58, 0x94
.syntax divided

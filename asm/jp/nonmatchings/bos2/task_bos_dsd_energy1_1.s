.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_1
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_1, %function
task_bos_dsd_energy1_1:
	.incbin "roms/B8CJ.gba", 0xc4aec, 0x16c
.syntax divided

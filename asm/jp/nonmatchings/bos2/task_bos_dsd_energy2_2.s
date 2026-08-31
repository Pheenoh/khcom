.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy2_2
	.thumb
	.thumb_func
	.type task_bos_dsd_energy2_2, %function
task_bos_dsd_energy2_2:
	.incbin "roms/B8CJ.gba", 0xc51c4, 0xb0
.syntax divided

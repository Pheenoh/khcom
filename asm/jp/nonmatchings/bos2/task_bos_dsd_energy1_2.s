.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_2
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_2, %function
task_bos_dsd_energy1_2:
	.incbin "roms/B8CJ.gba", 0xc4c58, 0xac
.syntax divided

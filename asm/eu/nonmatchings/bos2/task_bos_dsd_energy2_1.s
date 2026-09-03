.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_energy2_1
	.thumb
	.thumb_func
	.type task_bos_dsd_energy2_1, %function
task_bos_dsd_energy2_1:
	.incbin "roms/B8CP.gba", 0xc115c, 0x2b8
.syntax divided

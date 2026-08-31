.syntax unified
	.align 2, 0
	.global task_bos_dsd_rock_2
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_2, %function
task_bos_dsd_rock_2:
	.incbin "roms/B8CJ.gba", 0xc46ec, 0x84
.syntax divided

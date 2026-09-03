.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_rock_0
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_0, %function
task_bos_dsd_rock_0:
	.incbin "roms/B8CP.gba", 0xc0724, 0x1bc
.syntax divided

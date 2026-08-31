.syntax unified
	.align 2, 0
	.global task_bos_jf_rock_2
	.thumb
	.thumb_func
	.type task_bos_jf_rock_2, %function
task_bos_jf_rock_2:
	.incbin "roms/B8CJ.gba", 0xc12b8, 0x134
.syntax divided

.syntax unified
	.align 2, 0
	.global task_bos_jf_rock_3
	.thumb
	.thumb_func
	.type task_bos_jf_rock_3, %function
task_bos_jf_rock_3:
	.incbin "roms/B8CJ.gba", 0xc13ec, 0xec
.syntax divided

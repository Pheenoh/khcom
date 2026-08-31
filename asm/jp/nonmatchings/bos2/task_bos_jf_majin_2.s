.syntax unified
	.align 2, 0
	.global task_bos_jf_majin_2
	.thumb
	.thumb_func
	.type task_bos_jf_majin_2, %function
task_bos_jf_majin_2:
	.incbin "roms/B8CJ.gba", 0xbe868, 0x138
.syntax divided

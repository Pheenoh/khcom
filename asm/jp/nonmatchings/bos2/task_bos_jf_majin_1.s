.syntax unified
	.align 2, 0
	.global task_bos_jf_majin_1
	.thumb
	.thumb_func
	.type task_bos_jf_majin_1, %function
task_bos_jf_majin_1:
	.incbin "roms/B8CJ.gba", 0xbe760, 0x108
.syntax divided

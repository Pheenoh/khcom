.syntax unified
	.align 2, 0
	.global task_romcri_eff2_3
	.thumb
	.thumb_func
	.type task_romcri_eff2_3, %function
task_romcri_eff2_3:
	.incbin "roms/B8CJ.gba", 0x3fdbc, 0xc
.syntax divided

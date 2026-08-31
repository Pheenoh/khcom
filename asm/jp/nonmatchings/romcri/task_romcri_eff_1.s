.syntax unified
	.align 2, 0
	.global task_romcri_eff_1
	.thumb
	.thumb_func
	.type task_romcri_eff_1, %function
task_romcri_eff_1:
	.incbin "roms/B8CJ.gba", 0x3f7f4, 0x3dc
.syntax divided

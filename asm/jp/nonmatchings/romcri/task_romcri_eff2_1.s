.syntax unified
	.align 2, 0
	.global task_romcri_eff2_1
	.thumb
	.thumb_func
	.type task_romcri_eff2_1, %function
task_romcri_eff2_1:
	.incbin "roms/B8CJ.gba", 0x3fd08, 0xb4
.syntax divided

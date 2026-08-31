.syntax unified
	.align 2, 0
	.global task_romcri_eff2_0
	.thumb
	.thumb_func
	.type task_romcri_eff2_0, %function
task_romcri_eff2_0:
	.incbin "roms/B8CJ.gba", 0x3fbdc, 0x12c
.syntax divided

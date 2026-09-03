.syntax unified
	.text
	.align 2, 0
	.global task_romcri_eff_0
	.thumb
	.thumb_func
	.type task_romcri_eff_0, %function
task_romcri_eff_0:
	.incbin "roms/B8CP.gba", 0x43b10, 0xf0
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_fld_riku_1
	.thumb
	.thumb_func
	.type task_fld_riku_1, %function
task_fld_riku_1:
	.incbin "roms/B8CP.gba", 0x3a758, 0x60c
.syntax divided

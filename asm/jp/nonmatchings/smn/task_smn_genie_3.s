.syntax unified
	.align 2, 0
	.global task_smn_genie_3
	.thumb
	.thumb_func
	.type task_smn_genie_3, %function
task_smn_genie_3:
	.incbin "roms/B8CJ.gba", 0x44df0, 0x74
.syntax divided

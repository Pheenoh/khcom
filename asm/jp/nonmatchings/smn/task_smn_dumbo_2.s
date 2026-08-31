.syntax unified
	.align 2, 0
	.global task_smn_dumbo_2
	.thumb
	.thumb_func
	.type task_smn_dumbo_2, %function
task_smn_dumbo_2:
	.incbin "roms/B8CJ.gba", 0x44128, 0x128
.syntax divided

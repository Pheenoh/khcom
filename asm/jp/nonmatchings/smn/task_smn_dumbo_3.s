.syntax unified
	.align 2, 0
	.global task_smn_dumbo_3
	.thumb
	.thumb_func
	.type task_smn_dumbo_3, %function
task_smn_dumbo_3:
	.incbin "roms/B8CJ.gba", 0x44250, 0x54
.syntax divided

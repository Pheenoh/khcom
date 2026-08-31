.syntax unified
	.align 2, 0
	.global task_smn_mushu_2
	.thumb
	.thumb_func
	.type task_smn_mushu_2, %function
task_smn_mushu_2:
	.incbin "roms/B8CJ.gba", 0x43bd4, 0x120
.syntax divided

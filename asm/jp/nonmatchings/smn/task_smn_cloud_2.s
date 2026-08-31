.syntax unified
	.align 2, 0
	.global task_smn_cloud_2
	.thumb
	.thumb_func
	.type task_smn_cloud_2, %function
task_smn_cloud_2:
	.incbin "roms/B8CJ.gba", 0x41bbc, 0x160
.syntax divided

.syntax unified
	.align 2, 0
	.global task_smn_cloud_3
	.thumb
	.thumb_func
	.type task_smn_cloud_3, %function
task_smn_cloud_3:
	.incbin "roms/B8CJ.gba", 0x41d1c, 0x48
.syntax divided

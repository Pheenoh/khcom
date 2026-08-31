.syntax unified
	.align 2, 0
	.global task_smn_cloud_1
	.thumb
	.thumb_func
	.type task_smn_cloud_1, %function
task_smn_cloud_1:
	.incbin "roms/B8CJ.gba", 0x40f84, 0xc38
.syntax divided

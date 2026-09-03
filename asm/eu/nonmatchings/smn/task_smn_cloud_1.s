.syntax unified
	.text
	.align 2, 0
	.global task_smn_cloud_1
	.thumb
	.thumb_func
	.type task_smn_cloud_1, %function
task_smn_cloud_1:
	.incbin "roms/B8CP.gba", 0x45390, 0xc38
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_hum_cloud_1
	.thumb
	.thumb_func
	.type task_hum_cloud_1, %function
task_hum_cloud_1:
	.incbin "roms/B8CP.gba", 0x4e4a0, 0x13f4
.syntax divided

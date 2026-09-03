.syntax unified
	.text
	.align 2, 0
	.global task_hum_cloud_1
	.thumb
	.thumb_func
	.type task_hum_cloud_1, %function
task_hum_cloud_1:
	.incbin "roms/B8CJ.gba", 0x4a040, 0x13f4
.syntax divided

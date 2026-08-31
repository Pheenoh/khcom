.syntax unified
	.align 2, 0
	.global task_hum_cloud_3
	.thumb
	.thumb_func
	.type task_hum_cloud_3, %function
task_hum_cloud_3:
	.incbin "roms/B8CJ.gba", 0x4b440, 0xc
.syntax divided

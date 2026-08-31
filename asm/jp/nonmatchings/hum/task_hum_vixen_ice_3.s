.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_3
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_3, %function
task_hum_vixen_ice_3:
	.incbin "roms/B8CJ.gba", 0x55970, 0x20
.syntax divided

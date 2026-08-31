.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_1
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_1, %function
task_hum_vixen_ice_1:
	.incbin "roms/B8CJ.gba", 0x556dc, 0x1fc
.syntax divided

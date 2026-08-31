.syntax unified
	.align 2, 0
	.global task_hum_vixen_2
	.thumb
	.thumb_func
	.type task_hum_vixen_2, %function
task_hum_vixen_2:
	.incbin "roms/B8CJ.gba", 0x55448, 0x1c
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_hum_vixen_1
	.thumb
	.thumb_func
	.type task_hum_vixen_1, %function
task_hum_vixen_1:
	.incbin "roms/B8CP.gba", 0x58924, 0xf80
.syntax divided

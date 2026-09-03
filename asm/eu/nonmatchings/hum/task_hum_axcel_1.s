.syntax unified
	.text
	.align 2, 0
	.global task_hum_axcel_1
	.thumb
	.thumb_func
	.type task_hum_axcel_1, %function
task_hum_axcel_1:
	.incbin "roms/B8CP.gba", 0x56c90, 0x18cc
.syntax divided

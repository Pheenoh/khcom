.syntax unified
	.text
	.align 2, 0
	.global task_hum_mahluxia_1
	.thumb
	.thumb_func
	.type task_hum_mahluxia_1, %function
task_hum_mahluxia_1:
	.incbin "roms/B8CP.gba", 0x54234, 0xeec
.syntax divided

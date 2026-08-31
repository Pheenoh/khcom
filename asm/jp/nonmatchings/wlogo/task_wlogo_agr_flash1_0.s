.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash1_0
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash1_0, %function
task_wlogo_agr_flash1_0:
	.incbin "roms/B8CJ.gba", 0xb6678, 0x60
.syntax divided

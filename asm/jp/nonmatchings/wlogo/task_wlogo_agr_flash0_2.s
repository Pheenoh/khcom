.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash0_2
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash0_2, %function
task_wlogo_agr_flash0_2:
	.incbin "roms/B8CJ.gba", 0xb6634, 0x2c
.syntax divided

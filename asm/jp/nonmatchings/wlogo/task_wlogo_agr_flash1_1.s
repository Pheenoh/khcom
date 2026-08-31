.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash1_1
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash1_1, %function
task_wlogo_agr_flash1_1:
	.incbin "roms/B8CJ.gba", 0xb66d8, 0x28
.syntax divided

.syntax unified
	.align 2, 0
	.global task_wlogo_agr_smoke_3
	.thumb
	.thumb_func
	.type task_wlogo_agr_smoke_3, %function
task_wlogo_agr_smoke_3:
	.incbin "roms/B8CJ.gba", 0xb6594, 0x18
.syntax divided

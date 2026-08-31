.syntax unified
	.align 2, 0
	.global task_wlogo_agr_smoke_1
	.thumb
	.thumb_func
	.type task_wlogo_agr_smoke_1, %function
task_wlogo_agr_smoke_1:
	.incbin "roms/B8CJ.gba", 0xb653c, 0x28
.syntax divided

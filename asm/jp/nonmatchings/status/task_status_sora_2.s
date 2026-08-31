.syntax unified
	.align 2, 0
	.global task_status_sora_2
	.thumb
	.thumb_func
	.type task_status_sora_2, %function
task_status_sora_2:
	.incbin "roms/B8CJ.gba", 0xd7d8c, 0x44
.syntax divided

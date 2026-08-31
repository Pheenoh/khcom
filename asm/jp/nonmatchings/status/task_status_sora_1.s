.syntax unified
	.align 2, 0
	.global task_status_sora_1
	.thumb
	.thumb_func
	.type task_status_sora_1, %function
task_status_sora_1:
	.incbin "roms/B8CJ.gba", 0xd7d78, 0x14
.syntax divided

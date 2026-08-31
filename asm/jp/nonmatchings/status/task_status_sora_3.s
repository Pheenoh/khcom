.syntax unified
	.align 2, 0
	.global task_status_sora_3
	.thumb
	.thumb_func
	.type task_status_sora_3, %function
task_status_sora_3:
	.incbin "roms/B8CJ.gba", 0xd7dd0, 0x18
.syntax divided

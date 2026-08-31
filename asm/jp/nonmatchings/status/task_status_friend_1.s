.syntax unified
	.align 2, 0
	.global task_status_friend_1
	.thumb
	.thumb_func
	.type task_status_friend_1, %function
task_status_friend_1:
	.incbin "roms/B8CJ.gba", 0xd8b00, 0x4
.syntax divided

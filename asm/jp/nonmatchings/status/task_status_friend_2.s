.syntax unified
	.align 2, 0
	.global task_status_friend_2
	.thumb
	.thumb_func
	.type task_status_friend_2, %function
task_status_friend_2:
	.incbin "roms/B8CJ.gba", 0xd8b04, 0x70
.syntax divided

.syntax unified
	.align 2, 0
	.global task_room_name_2
	.thumb
	.thumb_func
	.type task_room_name_2, %function
task_room_name_2:
	.incbin "roms/B8CJ.gba", 0xf7d64, 0x6c
.syntax divided

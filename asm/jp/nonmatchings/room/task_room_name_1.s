.syntax unified
	.align 2, 0
	.global task_room_name_1
	.thumb
	.thumb_func
	.type task_room_name_1, %function
task_room_name_1:
	.incbin "roms/B8CJ.gba", 0xf7cac, 0xb8
.syntax divided

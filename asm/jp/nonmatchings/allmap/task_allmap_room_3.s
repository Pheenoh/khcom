.syntax unified
	.align 2, 0
	.global task_allmap_room_3
	.thumb
	.thumb_func
	.type task_allmap_room_3, %function
task_allmap_room_3:
	.incbin "roms/B8CJ.gba", 0xd3aa8, 0x2c
.syntax divided

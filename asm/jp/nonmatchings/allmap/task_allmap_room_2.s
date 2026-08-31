.syntax unified
	.align 2, 0
	.global task_allmap_room_2
	.thumb
	.thumb_func
	.type task_allmap_room_2, %function
task_allmap_room_2:
	.incbin "roms/B8CJ.gba", 0xd3968, 0x140
.syntax divided

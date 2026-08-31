.syntax unified
	.align 2, 0
	.global task_allmap_room_1
	.thumb
	.thumb_func
	.type task_allmap_room_1, %function
task_allmap_room_1:
	.incbin "roms/B8CJ.gba", 0xd3964, 0x4
.syntax divided

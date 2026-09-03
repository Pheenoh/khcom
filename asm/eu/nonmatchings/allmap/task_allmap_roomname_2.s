.syntax unified
	.text
	.align 2, 0
	.global task_allmap_roomname_2
	.thumb
	.thumb_func
	.type task_allmap_roomname_2, %function
task_allmap_roomname_2:
	.incbin "roms/B8CP.gba", 0xd06a0, 0x38
.syntax divided

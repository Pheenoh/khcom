.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_2
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_2, %function
task_allmap_doorinfo_2:
	.incbin "roms/B8CJ.gba", 0xd4b1c, 0x44
.syntax divided

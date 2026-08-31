.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_1
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_1, %function
task_allmap_doorinfo_1:
	.incbin "roms/B8CJ.gba", 0xd4848, 0xb8
.syntax divided

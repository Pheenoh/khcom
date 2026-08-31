.syntax unified
	.align 2, 0
	.global task_btl_raid_3
	.thumb
	.thumb_func
	.type task_btl_raid_3, %function
task_btl_raid_3:
	.incbin "roms/B8CJ.gba", 0x40a68, 0x1c
.syntax divided

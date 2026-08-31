.syntax unified
	.align 2, 0
	.global task_btl_raid_0
	.thumb
	.thumb_func
	.type task_btl_raid_0, %function
task_btl_raid_0:
	.incbin "roms/B8CJ.gba", 0x40214, 0x2a0
.syntax divided

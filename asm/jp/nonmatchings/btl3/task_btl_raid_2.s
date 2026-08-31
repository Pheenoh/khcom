.syntax unified
	.align 2, 0
	.global task_btl_raid_2
	.thumb
	.thumb_func
	.type task_btl_raid_2, %function
task_btl_raid_2:
	.incbin "roms/B8CJ.gba", 0x4096c, 0xfc
.syntax divided

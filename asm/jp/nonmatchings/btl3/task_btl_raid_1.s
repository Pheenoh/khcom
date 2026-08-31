.syntax unified
	.align 2, 0
	.global task_btl_raid_1
	.thumb
	.thumb_func
	.type task_btl_raid_1, %function
task_btl_raid_1:
	.incbin "roms/B8CJ.gba", 0x404b4, 0x4b8
.syntax divided

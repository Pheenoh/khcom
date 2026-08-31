.syntax unified
	.align 2, 0
	.global task_title_lumichange_2
	.thumb
	.thumb_func
	.type task_title_lumichange_2, %function
task_title_lumichange_2:
	.incbin "roms/B8CJ.gba", 0xd700c, 0x84
.syntax divided

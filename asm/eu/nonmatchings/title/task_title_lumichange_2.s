.syntax unified
	.text
	.align 2, 0
	.global task_title_lumichange_2
	.thumb
	.thumb_func
	.type task_title_lumichange_2, %function
task_title_lumichange_2:
	.incbin "roms/B8CP.gba", 0xd3c08, 0x98
.syntax divided

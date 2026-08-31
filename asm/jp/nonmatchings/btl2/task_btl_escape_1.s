.syntax unified
	.align 2, 0
	.global task_btl_escape_1
	.thumb
	.thumb_func
	.type task_btl_escape_1, %function
task_btl_escape_1:
	.incbin "roms/B8CJ.gba", 0x30990, 0xd4
.syntax divided

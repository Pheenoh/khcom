.syntax unified
	.text
	.align 2, 0
	.global task_btl_escape_0
	.thumb
	.thumb_func
	.type task_btl_escape_0, %function
task_btl_escape_0:
	.incbin "roms/B8CP.gba", 0x34ca8, 0xe0
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_status_tab_0
	.thumb
	.thumb_func
	.type task_status_tab_0, %function
task_status_tab_0:
	.incbin "roms/B8CP.gba", 0xd4904, 0x98
.syntax divided

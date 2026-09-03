.syntax unified
	.text
	.align 2, 0
	.global task_status_tab_1
	.thumb
	.thumb_func
	.type task_status_tab_1, %function
task_status_tab_1:
	.incbin "roms/B8CP.gba", 0xd499c, 0x30
.syntax divided

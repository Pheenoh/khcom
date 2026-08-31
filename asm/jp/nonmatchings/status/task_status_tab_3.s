.syntax unified
	.align 2, 0
	.global task_status_tab_3
	.thumb
	.thumb_func
	.type task_status_tab_3, %function
task_status_tab_3:
	.incbin "roms/B8CJ.gba", 0xd7cac, 0x24
.syntax divided

.syntax unified
	.align 2, 0
	.global task_status_tab_0
	.thumb
	.thumb_func
	.type task_status_tab_0, %function
task_status_tab_0:
	.incbin "roms/B8CJ.gba", 0xd7bc8, 0x7c
.syntax divided

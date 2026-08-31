.syntax unified
	.align 2, 0
	.global task_status_meswindow_2
	.thumb
	.thumb_func
	.type task_status_meswindow_2, %function
task_status_meswindow_2:
	.incbin "roms/B8CJ.gba", 0xd89f0, 0x28
.syntax divided

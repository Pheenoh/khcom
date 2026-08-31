.syntax unified
	.align 2, 0
	.global task_status_meswindow_3
	.thumb
	.thumb_func
	.type task_status_meswindow_3, %function
task_status_meswindow_3:
	.incbin "roms/B8CJ.gba", 0xd8a18, 0xc
.syntax divided

.syntax unified
	.align 2, 0
	.global task_status_meswindow_1
	.thumb
	.thumb_func
	.type task_status_meswindow_1, %function
task_status_meswindow_1:
	.incbin "roms/B8CJ.gba", 0xd8978, 0x78
.syntax divided

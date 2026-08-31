.syntax unified
	.align 2, 0
	.global task_title_logo_2
	.thumb
	.thumb_func
	.type task_title_logo_2, %function
task_title_logo_2:
	.incbin "roms/B8CJ.gba", 0xd64ec, 0xc4
.syntax divided

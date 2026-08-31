.syntax unified
	.align 2, 0
	.global task_title_logo_3
	.thumb
	.thumb_func
	.type task_title_logo_3, %function
task_title_logo_3:
	.incbin "roms/B8CJ.gba", 0xd65b0, 0x64
.syntax divided

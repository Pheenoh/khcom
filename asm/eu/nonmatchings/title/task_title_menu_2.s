.syntax unified
	.text
	.align 2, 0
	.global task_title_menu_2
	.thumb
	.thumb_func
	.type task_title_menu_2, %function
task_title_menu_2:
	.incbin "roms/B8CP.gba", 0xd3934, 0xe8
.syntax divided

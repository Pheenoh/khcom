.syntax unified
	.align 2, 0
	.global task_title_menu_2
	.thumb
	.thumb_func
	.type task_title_menu_2, %function
task_title_menu_2:
	.incbin "roms/B8CJ.gba", 0xd6e44, 0x90
.syntax divided

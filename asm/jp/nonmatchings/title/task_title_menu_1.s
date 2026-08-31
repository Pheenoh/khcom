.syntax unified
	.align 2, 0
	.global task_title_menu_1
	.thumb
	.thumb_func
	.type task_title_menu_1, %function
task_title_menu_1:
	.incbin "roms/B8CJ.gba", 0xd6abc, 0x3c
.syntax divided

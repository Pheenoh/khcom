.syntax unified
	.align 2, 0
	.global task_poo_ti_board_2
	.thumb
	.thumb_func
	.type task_poo_ti_board_2, %function
task_poo_ti_board_2:
	.incbin "roms/B8CJ.gba", 0xcf874, 0xb4
.syntax divided

.syntax unified
	.align 2, 0
	.global task_poo_ti_board_1
	.thumb
	.thumb_func
	.type task_poo_ti_board_1, %function
task_poo_ti_board_1:
	.incbin "roms/B8CJ.gba", 0xcf848, 0x2c
.syntax divided

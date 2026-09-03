.syntax unified
	.text
	.align 2, 0
	.global stock_mes_disp_1
	.thumb
	.thumb_func
	.type stock_mes_disp_1, %function
stock_mes_disp_1:
	.incbin "roms/B8CJ.gba", 0xd8d50, 0xa0
.syntax divided

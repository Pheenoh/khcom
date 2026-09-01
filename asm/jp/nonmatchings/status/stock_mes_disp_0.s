.syntax unified
	.align 2, 0
	.global stock_mes_disp_0
	.thumb
	.thumb_func
	.type stock_mes_disp_0, %function
stock_mes_disp_0:
	.incbin "roms/B8CJ.gba", 0xd8c58, 0xf8
.syntax divided

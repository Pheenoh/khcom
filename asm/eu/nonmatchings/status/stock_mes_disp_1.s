.syntax unified
	.text
	.align 2, 0
	.global stock_mes_disp_1
	.thumb
	.thumb_func
	.type stock_mes_disp_1, %function
stock_mes_disp_1:
	.incbin "roms/B8CP.gba", 0xd5ae4, 0xa0
.syntax divided

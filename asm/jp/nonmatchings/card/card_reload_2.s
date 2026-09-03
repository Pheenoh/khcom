.syntax unified
	.align 2, 0
	.global card_reload_2
	.thumb
	.thumb_func
	.type card_reload_2, %function
card_reload_2:
	.incbin "roms/B8CJ.gba", 0x7da10, 0x178
.syntax divided

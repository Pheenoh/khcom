.syntax unified
	.text
	.align 2, 0
	.global eu_080ABA38
	.thumb
	.thumb_func
	.type eu_080ABA38, %function
eu_080ABA38:
	.incbin "roms/B8CP.gba", 0xaba38, 0x44
	.align 2, 0
	.global eu_080ABA7C
	.thumb
	.thumb_func
	.type eu_080ABA7C, %function
eu_080ABA7C:
	.incbin "roms/B8CP.gba", 0xaba7c, 0x10
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global SetBgMode2
	.thumb
	.thumb_func
	.type SetBgMode2, %function
SetBgMode2:
	.incbin "roms/B8CP.gba", 0x509c, 0xa0
.syntax divided

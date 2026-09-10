.syntax unified
	.text
	.align 2, 0
	.global eu_08060DF8
	.thumb
	.thumb_func
	.type eu_08060DF8, %function
eu_08060DF8:
	.incbin "roms/B8CP.gba", 0x60df8, 0x790
	.size eu_08060DF8, .-eu_08060DF8
.syntax divided

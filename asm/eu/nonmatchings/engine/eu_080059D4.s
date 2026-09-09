.syntax unified
	.text
	.align 2, 0
	.align 2, 0
	.global eu_08005A14
	.thumb
	.thumb_func
	.type eu_08005A14, %function
eu_08005A14:
	.incbin "roms/B8CP.gba", 0x5a14, 0x8
	.align 2, 0
	.global eu_08005A1C
	.thumb
	.thumb_func
	.type eu_08005A1C, %function
eu_08005A1C:
	.incbin "roms/B8CP.gba", 0x5a1c, 0xc0
	.align 2, 0
	.global eu_08005ADC
	.thumb
	.thumb_func
	.type eu_08005ADC, %function
eu_08005ADC:
	.incbin "roms/B8CP.gba", 0x5adc, 0x48
.syntax divided

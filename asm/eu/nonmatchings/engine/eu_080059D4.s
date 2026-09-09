.syntax unified
	.text
	.align 2, 0
	.align 2, 0
	.align 2, 0
	.align 2, 0
	.global eu_08005ADC
	.thumb
	.thumb_func
	.type eu_08005ADC, %function
eu_08005ADC:
	.incbin "roms/B8CP.gba", 0x5adc, 0x48
.syntax divided

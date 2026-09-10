.syntax unified
	.text
	.align 2, 0
	.global eu_08060C8C
	.thumb
	.thumb_func
	.type eu_08060C8C, %function
eu_08060C8C:
	.incbin "roms/B8CP.gba", 0x60c8c, 0x16c
	.size eu_08060C8C, .-eu_08060C8C
.syntax divided

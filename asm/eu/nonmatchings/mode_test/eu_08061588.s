.syntax unified
	.text
	.align 2, 0
	.global eu_08061588
	.thumb
	.thumb_func
	.type eu_08061588, %function
eu_08061588:
	.incbin "roms/B8CP.gba", 0x61588, 0x110
	.size eu_08061588, .-eu_08061588
.syntax divided

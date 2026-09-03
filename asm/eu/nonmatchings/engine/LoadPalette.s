.syntax unified
	.text
	.align 2, 0
	.global LoadPalette
	.thumb
	.thumb_func
	.type LoadPalette, %function
LoadPalette:
	.incbin "roms/B8CP.gba", 0x5ee8, 0x78
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global LoadObjPalette
	.thumb
	.thumb_func
	.type LoadObjPalette, %function
LoadObjPalette:
	.incbin "roms/B8CP.gba", 0x2a8c, 0x198
.syntax divided

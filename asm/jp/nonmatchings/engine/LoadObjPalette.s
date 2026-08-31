.syntax unified
	.align 2, 0
	.global LoadObjPalette
	.thumb
	.thumb_func
	.type LoadObjPalette, %function
LoadObjPalette:
	.incbin "roms/B8CJ.gba", 0x2a14, 0x198
.syntax divided

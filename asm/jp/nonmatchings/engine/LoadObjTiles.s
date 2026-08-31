.syntax unified
	.align 2, 0
	.global LoadObjTiles
	.thumb
	.thumb_func
	.type LoadObjTiles, %function
LoadObjTiles:
	.incbin "roms/B8CJ.gba", 0x26a4, 0x1a8
.syntax divided

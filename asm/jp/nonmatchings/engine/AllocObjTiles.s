.syntax unified
	.align 2, 0
	.global AllocObjTiles
	.thumb
	.thumb_func
	.type AllocObjTiles, %function
AllocObjTiles:
	.incbin "roms/B8CJ.gba", 0x28f8, 0x118
.syntax divided

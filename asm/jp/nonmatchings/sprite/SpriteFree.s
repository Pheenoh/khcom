.syntax unified
	.align 2, 0
	.global SpriteFree
	.thumb
	.thumb_func
	.type SpriteFree, %function
SpriteFree:
	.incbin "roms/B8CJ.gba", 0x1d9c, 0x14
.syntax divided

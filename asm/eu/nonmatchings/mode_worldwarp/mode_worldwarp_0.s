.syntax unified
	.text
	.align 2, 0
	.global mode_worldwarp_0
	.thumb
	.thumb_func
	.type mode_worldwarp_0, %function
mode_worldwarp_0:
	.incbin "roms/B8CP.gba", 0xfed0c, 0x9ec
.syntax divided

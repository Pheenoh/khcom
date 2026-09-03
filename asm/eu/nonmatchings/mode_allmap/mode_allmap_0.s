.syntax unified
	.text
	.align 2, 0
	.global mode_allmap_0
	.thumb
	.thumb_func
	.type mode_allmap_0, %function
mode_allmap_0:
	.incbin "roms/B8CP.gba", 0xcf9d0, 0x1b0
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global Mapcard_2
	.thumb
	.thumb_func
	.type Mapcard_2, %function
Mapcard_2:
	.incbin "roms/B8CP.gba", 0x94e68, 0x11c
.syntax divided

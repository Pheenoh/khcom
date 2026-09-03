.syntax unified
	.text
	.align 2, 0
	.global msgface_1
	.thumb
	.thumb_func
	.type msgface_1, %function
msgface_1:
	.incbin "roms/B8CJ.gba", 0x736e4, 0x1cc
.syntax divided

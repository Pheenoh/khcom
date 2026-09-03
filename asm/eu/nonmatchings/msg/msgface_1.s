.syntax unified
	.text
	.align 2, 0
	.global msgface_1
	.thumb
	.thumb_func
	.type msgface_1, %function
msgface_1:
	.incbin "roms/B8CP.gba", 0x72c28, 0x1cc
.syntax divided

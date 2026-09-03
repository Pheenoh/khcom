.syntax unified
	.text
	.align 2, 0
	.global SoundMainBTM
	.thumb
	.thumb_func
	.type SoundMainBTM, %function
SoundMainBTM:
	.incbin "roms/B8CP.gba", 0x11e098, 0x18
.syntax divided

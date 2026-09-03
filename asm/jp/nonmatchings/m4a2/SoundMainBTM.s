.syntax unified
	.text
	.align 2, 0
	.global SoundMainBTM
	.thumb
	.thumb_func
	.type SoundMainBTM, %function
SoundMainBTM:
	.incbin "roms/B8CJ.gba", 0x11f5f4, 0x18
.syntax divided

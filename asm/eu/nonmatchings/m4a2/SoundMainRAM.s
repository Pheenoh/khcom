.syntax unified
	.text
	.align 2, 0
	.global SoundMainRAM
	.thumb
	.thumb_func
	.type SoundMainRAM, %function
SoundMainRAM:
	.incbin "roms/B8CP.gba", 0x11dcf4, 0x3a4
.syntax divided

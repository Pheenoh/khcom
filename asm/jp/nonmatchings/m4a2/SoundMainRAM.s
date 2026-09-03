.syntax unified
	.text
	.align 2, 0
	.global SoundMainRAM
	.thumb
	.thumb_func
	.type SoundMainRAM, %function
SoundMainRAM:
	.incbin "roms/B8CJ.gba", 0x11f250, 0x3a4
.syntax divided

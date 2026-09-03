.syntax unified
	.text
	.align 2, 0
	.global SoundMain
	.thumb
	.thumb_func
	.type SoundMain, %function
SoundMain:
	.incbin "roms/B8CP.gba", 0x11dc70, 0x84
.syntax divided

.syntax unified
	.align 2, 0
	.global SoundMain
	.thumb
	.thumb_func
	.type SoundMain, %function
SoundMain:
	.incbin "roms/B8CJ.gba", 0x11f1cc, 0x84
.syntax divided

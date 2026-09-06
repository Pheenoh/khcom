.syntax unified
	.text
	.align 2, 0
	.global MovieSetupAudioCodec
	.thumb
	.thumb_func
	.type MovieSetupAudioCodec, %function
MovieSetupAudioCodec:
	.incbin "roms/B8CP.gba", 0x1175fc, 0x158
.syntax divided

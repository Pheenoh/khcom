.syntax unified
	.text
	.align 2, 0
	.global MovieSetupAudioCodec
	.thumb
	.thumb_func
	.type MovieSetupAudioCodec, %function
MovieSetupAudioCodec:
	.incbin "roms/B8CJ.gba", 0x118b58, 0x158
.syntax divided

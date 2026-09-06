.syntax unified
	.text
	.align 2, 0
	.global MovieSetupVideoCodec
	.thumb
	.thumb_func
	.type MovieSetupVideoCodec, %function
MovieSetupVideoCodec:
	.incbin "roms/B8CJ.gba", 0x1186d8, 0x480
.syntax divided

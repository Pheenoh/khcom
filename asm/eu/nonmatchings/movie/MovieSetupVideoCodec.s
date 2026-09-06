.syntax unified
	.text
	.align 2, 0
	.global MovieSetupVideoCodec
	.thumb
	.thumb_func
	.type MovieSetupVideoCodec, %function
MovieSetupVideoCodec:
	.incbin "roms/B8CP.gba", 0x11717c, 0x480
.syntax divided

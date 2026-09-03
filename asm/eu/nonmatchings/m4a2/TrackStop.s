.syntax unified
	.text
	.align 2, 0
	.global TrackStop
	.thumb
	.thumb_func
	.type TrackStop, %function
TrackStop:
	.incbin "roms/B8CP.gba", 0x11e548, 0x4c
.syntax divided

.syntax unified
	.align 2, 0
	.global TrackStop
	.thumb
	.thumb_func
	.type TrackStop, %function
TrackStop:
	.incbin "roms/B8CJ.gba", 0x11faa4, 0x7c
.syntax divided

.syntax unified
	.align 2, 0
	.global ApplyIntrCallbacks
	.thumb
	.thumb_func
	.type ApplyIntrCallbacks, %function
ApplyIntrCallbacks:
	.incbin "roms/B8CJ.gba", 0x628, 0x38
.syntax divided

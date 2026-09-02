.syntax unified
	.align 2, 0
	.global RealClearChain
	.thumb
	.thumb_func
	.type RealClearChain, %function
RealClearChain:
	.incbin "roms/B8CJ.gba", 0x11f60c, 0x20
.syntax divided

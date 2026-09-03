.syntax unified
	.text
	.align 2, 0
	.global RealClearChain
	.thumb
	.thumb_func
	.type RealClearChain, %function
RealClearChain:
	.incbin "roms/B8CP.gba", 0x11e0b0, 0x20
.syntax divided

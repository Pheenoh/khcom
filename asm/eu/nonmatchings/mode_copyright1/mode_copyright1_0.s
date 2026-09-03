.syntax unified
	.text
	.align 2, 0
	.global mode_copyright1_0
	.thumb
	.thumb_func
	.type mode_copyright1_0, %function
mode_copyright1_0:
	.incbin "roms/B8CP.gba", 0xd3cb8, 0x148
.syntax divided

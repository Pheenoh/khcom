.syntax unified
	.text
	.align 2, 0
	.global VTransReset
	.thumb
	.thumb_func
	.type VTransReset, %function
VTransReset:
	.incbin "roms/B8CP.gba", 0x43dc, 0x5c
.syntax divided

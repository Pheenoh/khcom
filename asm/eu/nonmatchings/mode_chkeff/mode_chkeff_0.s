.syntax unified
	.text
	.align 2, 0
	.global mode_chkeff_0
	.thumb
	.thumb_func
	.type mode_chkeff_0, %function
mode_chkeff_0:
	.incbin "roms/B8CP.gba", 0xc314, 0x118
.syntax divided

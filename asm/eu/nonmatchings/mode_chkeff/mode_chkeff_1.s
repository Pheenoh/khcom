.syntax unified
	.text
	.align 2, 0
	.global mode_chkeff_1
	.thumb
	.thumb_func
	.type mode_chkeff_1, %function
mode_chkeff_1:
	.incbin "roms/B8CP.gba", 0xc42c, 0x324
.syntax divided

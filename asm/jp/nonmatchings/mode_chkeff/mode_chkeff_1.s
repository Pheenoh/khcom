.syntax unified
	.text
	.align 2, 0
	.global mode_chkeff_1
	.thumb
	.thumb_func
	.type mode_chkeff_1, %function
mode_chkeff_1:
	.incbin "roms/B8CJ.gba", 0xbc50, 0x324
.syntax divided

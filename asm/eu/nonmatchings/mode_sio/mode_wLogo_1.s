.syntax unified
	.text
	.align 2, 0
	.global mode_wLogo_1
	.thumb
	.thumb_func
	.type mode_wLogo_1, %function
mode_wLogo_1:
	.incbin "roms/B8CP.gba", 0xb02c0, 0x190
.syntax divided

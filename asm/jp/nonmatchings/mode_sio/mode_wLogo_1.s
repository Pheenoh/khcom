.syntax unified
	.text
	.align 2, 0
	.global mode_wLogo_1
	.thumb
	.thumb_func
	.type mode_wLogo_1, %function
mode_wLogo_1:
	.incbin "roms/B8CJ.gba", 0xb4048, 0x188
.syntax divided

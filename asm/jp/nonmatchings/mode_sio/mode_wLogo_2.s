.syntax unified
	.align 2, 0
	.global mode_wLogo_2
	.thumb
	.thumb_func
	.type mode_wLogo_2, %function
mode_wLogo_2:
	.incbin "roms/B8CJ.gba", 0xb41d0, 0x38
.syntax divided

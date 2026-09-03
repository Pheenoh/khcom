.syntax unified
	.text
	.align 2, 0
	.global mode_status_0
	.thumb
	.thumb_func
	.type mode_status_0, %function
mode_status_0:
	.incbin "roms/B8CP.gba", 0xd40b0, 0x180
.syntax divided

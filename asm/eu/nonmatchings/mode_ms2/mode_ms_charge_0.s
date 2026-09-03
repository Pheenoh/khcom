.syntax unified
	.text
	.align 2, 0
	.global mode_ms_charge_0
	.thumb
	.thumb_func
	.type mode_ms_charge_0, %function
mode_ms_charge_0:
	.incbin "roms/B8CP.gba", 0x104dd4, 0x590
.syntax divided

.syntax unified
	.align 2, 0
	.global mode_ms_charge_0
	.thumb
	.thumb_func
	.type mode_ms_charge_0, %function
mode_ms_charge_0:
	.incbin "roms/B8CJ.gba", 0x106900, 0x550
.syntax divided

.syntax unified
	.align 2, 0
	.global mode_ms_charge_1
	.thumb
	.thumb_func
	.type mode_ms_charge_1, %function
mode_ms_charge_1:
	.incbin "roms/B8CJ.gba", 0x106e50, 0x160
.syntax divided

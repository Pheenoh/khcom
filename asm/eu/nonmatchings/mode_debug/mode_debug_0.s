.syntax unified
	.text
	.align 2, 0
	.global mode_debug_0
	.thumb
	.thumb_func
	.type mode_debug_0, %function
mode_debug_0:
	.incbin "roms/B8CP.gba", 0xb364, 0x164
.syntax divided

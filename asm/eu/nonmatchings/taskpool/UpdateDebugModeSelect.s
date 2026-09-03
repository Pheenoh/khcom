.syntax unified
	.text
	.align 2, 0
	.global UpdateDebugModeSelect
	.thumb
	.thumb_func
	.type UpdateDebugModeSelect, %function
UpdateDebugModeSelect:
	.incbin "roms/B8CP.gba", 0x137c, 0x80
.syntax divided

.syntax unified
	.align 2, 0
	.global UpdateKeyState
	.thumb
	.thumb_func
	.type UpdateKeyState, %function
UpdateKeyState:
	.incbin "roms/B8CJ.gba", 0x1938, 0x428
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global SaveSetFileLargeState
	.thumb
	.thumb_func
	.type SaveSetFileLargeState, %function
SaveSetFileLargeState:
	.incbin "roms/B8CP.gba", 0x9630, 0xe8
.syntax divided

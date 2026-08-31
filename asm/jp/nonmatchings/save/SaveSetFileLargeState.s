.syntax unified
	.align 2, 0
	.global SaveSetFileLargeState
	.thumb
	.thumb_func
	.type SaveSetFileLargeState, %function
SaveSetFileLargeState:
	.incbin "roms/B8CJ.gba", 0x9330, 0xe8
.syntax divided

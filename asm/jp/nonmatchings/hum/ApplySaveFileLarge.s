.syntax unified
	.align 2, 0
	.global ApplySaveFileLarge
	.thumb
	.thumb_func
	.type ApplySaveFileLarge, %function
ApplySaveFileLarge:
	.incbin "roms/B8CJ.gba", 0x5a358, 0xa8
.syntax divided

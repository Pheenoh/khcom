.syntax unified
	.align 2, 0
	.global MakeSaveFileLarge
	.thumb
	.thumb_func
	.type MakeSaveFileLarge, %function
MakeSaveFileLarge:
	.incbin "roms/B8CJ.gba", 0x59f68, 0xe0
.syntax divided

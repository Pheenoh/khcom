.syntax unified
	.align 2, 0
	.global SaveWriteFileLarge
	.thumb
	.thumb_func
	.type SaveWriteFileLarge, %function
SaveWriteFileLarge:
	.incbin "roms/B8CJ.gba", 0x9298, 0x98
.syntax divided

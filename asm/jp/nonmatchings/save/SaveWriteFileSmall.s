.syntax unified
	.align 2, 0
	.global SaveWriteFileSmall
	.thumb
	.thumb_func
	.type SaveWriteFileSmall, %function
SaveWriteFileSmall:
	.incbin "roms/B8CJ.gba", 0x963c, 0x98
.syntax divided

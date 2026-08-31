.syntax unified
	.align 2, 0
	.global MakeSaveFileSmall
	.thumb
	.thumb_func
	.type MakeSaveFileSmall, %function
MakeSaveFileSmall:
	.incbin "roms/B8CJ.gba", 0x5a048, 0xbc
.syntax divided

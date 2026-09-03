.syntax unified
	.text
	.align 2, 0
	.global MakeSaveHeaderData
	.thumb
	.thumb_func
	.type MakeSaveHeaderData, %function
MakeSaveHeaderData:
	.incbin "roms/B8CP.gba", 0x5e268, 0x114
.syntax divided

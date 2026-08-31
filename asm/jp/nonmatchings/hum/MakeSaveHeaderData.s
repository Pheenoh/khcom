.syntax unified
	.align 2, 0
	.global MakeSaveHeaderData
	.thumb
	.thumb_func
	.type MakeSaveHeaderData, %function
MakeSaveHeaderData:
	.incbin "roms/B8CJ.gba", 0x59ddc, 0x108
.syntax divided

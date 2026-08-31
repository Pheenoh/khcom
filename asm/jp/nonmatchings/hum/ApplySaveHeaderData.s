.syntax unified
	.align 2, 0
	.global ApplySaveHeaderData
	.thumb
	.thumb_func
	.type ApplySaveHeaderData, %function
ApplySaveHeaderData:
	.incbin "roms/B8CJ.gba", 0x5a104, 0x1b8
.syntax divided

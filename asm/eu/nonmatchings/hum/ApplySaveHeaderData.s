.syntax unified
	.text
	.align 2, 0
	.global ApplySaveHeaderData
	.thumb
	.thumb_func
	.type ApplySaveHeaderData, %function
ApplySaveHeaderData:
	.incbin "roms/B8CP.gba", 0x5e59c, 0x1c0
.syntax divided

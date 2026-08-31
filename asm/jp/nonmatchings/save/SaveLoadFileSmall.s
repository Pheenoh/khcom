.syntax unified
	.align 2, 0
	.global SaveLoadFileSmall
	.thumb
	.thumb_func
	.type SaveLoadFileSmall, %function
SaveLoadFileSmall:
	.incbin "roms/B8CJ.gba", 0x95c8, 0x74
.syntax divided

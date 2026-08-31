.syntax unified
	.align 2, 0
	.global ApplySaveFileSmall
	.thumb
	.thumb_func
	.type ApplySaveFileSmall, %function
ApplySaveFileSmall:
	.incbin "roms/B8CJ.gba", 0x5a400, 0x84
.syntax divided

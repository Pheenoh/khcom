.syntax unified
	.align 2, 0
	.global ApplySaveSystem
	.thumb
	.thumb_func
	.type ApplySaveSystem, %function
ApplySaveSystem:
	.incbin "roms/B8CJ.gba", 0x5a2bc, 0x9c
.syntax divided

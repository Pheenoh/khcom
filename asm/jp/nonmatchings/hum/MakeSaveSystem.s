.syntax unified
	.align 2, 0
	.global MakeSaveSystem
	.thumb
	.thumb_func
	.type MakeSaveSystem, %function
MakeSaveSystem:
	.incbin "roms/B8CJ.gba", 0x59ee4, 0x84
.syntax divided

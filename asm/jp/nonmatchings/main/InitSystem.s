.syntax unified
	.align 2, 0
	.global InitSystem
	.thumb
	.thumb_func
	.type InitSystem, %function
InitSystem:
	.incbin "roms/B8CJ.gba", 0x334, 0x118
.syntax divided

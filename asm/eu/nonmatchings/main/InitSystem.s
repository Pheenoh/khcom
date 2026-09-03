.syntax unified
	.text
	.align 2, 0
	.global InitSystem
	.thumb
	.thumb_func
	.type InitSystem, %function
InitSystem:
	.incbin "roms/B8CP.gba", 0x390, 0x100
.syntax divided

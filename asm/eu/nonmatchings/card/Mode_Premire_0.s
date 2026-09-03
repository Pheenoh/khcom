.syntax unified
	.text
	.align 2, 0
	.global Mode_Premire_0
	.thumb
	.thumb_func
	.type Mode_Premire_0, %function
Mode_Premire_0:
	.incbin "roms/B8CP.gba", 0x9df24, 0x9c
.syntax divided

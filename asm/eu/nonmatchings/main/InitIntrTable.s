.syntax unified
	.text
	.align 2, 0
	.global InitIntrTable
	.thumb
	.thumb_func
	.type InitIntrTable, %function
InitIntrTable:
	.incbin "roms/B8CP.gba", 0x5f4, 0x78
.syntax divided

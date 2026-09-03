.syntax unified
	.text
	.align 2, 0
	.global InitIntrTable
	.thumb
	.thumb_func
	.type InitIntrTable, %function
InitIntrTable:
	.incbin "roms/B8CJ.gba", 0x5b0, 0x78
.syntax divided

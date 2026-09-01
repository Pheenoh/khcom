.syntax unified
	.align 2, 0
	.global GetKeysRepeat
	.thumb
	.thumb_func
	.type GetKeysRepeat, %function
GetKeysRepeat:
	.incbin "roms/B8CJ.gba", 0x139c, 0xd4
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global RegisterRamReset
	.thumb
	.thumb_func
	.type RegisterRamReset, %function
RegisterRamReset:
	.incbin "roms/B8CJ.gba", 0x118068, 0x4
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global RegisterRamReset
	.thumb
	.thumb_func
	.type RegisterRamReset, %function
RegisterRamReset:
	.incbin "roms/B8CP.gba", 0x116b0c, 0x4
.syntax divided

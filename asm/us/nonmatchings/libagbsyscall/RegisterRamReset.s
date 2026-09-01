.syntax unified
	.align 2, 0
	.global RegisterRamReset
	.thumb
	.thumb_func
	.type RegisterRamReset, %function
RegisterRamReset: @ 08117FEC
	.byte 0x01, 0xDF, 0x70, 0x47
.syntax divided

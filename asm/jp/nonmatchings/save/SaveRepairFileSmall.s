.syntax unified
	.align 2, 0
	.global SaveRepairFileSmall
	.thumb
	.thumb_func
	.type SaveRepairFileSmall, %function
SaveRepairFileSmall:
	.incbin "roms/B8CJ.gba", 0x94ec, 0xdc
.syntax divided

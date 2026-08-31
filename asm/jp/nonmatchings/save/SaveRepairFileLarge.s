.syntax unified
	.align 2, 0
	.global SaveRepairFileLarge
	.thumb
	.thumb_func
	.type SaveRepairFileLarge, %function
SaveRepairFileLarge:
	.incbin "roms/B8CJ.gba", 0x9150, 0xd0
.syntax divided

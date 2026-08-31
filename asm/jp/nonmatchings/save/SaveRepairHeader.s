.syntax unified
	.align 2, 0
	.global SaveRepairHeader
	.thumb
	.thumb_func
	.type SaveRepairHeader, %function
SaveRepairHeader:
	.incbin "roms/B8CJ.gba", 0x8bbc, 0x9c
.syntax divided

.syntax unified
	.align 2, 0
	.global SerialIntrDummy
	.thumb
	.thumb_func
	.type SerialIntrDummy, %function
SerialIntrDummy:
	.incbin "roms/B8CJ.gba", 0x5ac, 0x4
.syntax divided

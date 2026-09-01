.syntax unified
	.align 2, 0
	.global VBlankIntrSio
	.thumb
	.thumb_func
	.type VBlankIntrSio, %function
VBlankIntrSio:
	.incbin "roms/B8CJ.gba", 0x660, 0xb4
.syntax divided

.syntax unified
	.align 2, 0
	.global RequestDma3Copy
	.thumb
	.thumb_func
	.type RequestDma3Copy, %function
RequestDma3Copy:
	.incbin "roms/B8CJ.gba", 0x43b4, 0x88
.syntax divided

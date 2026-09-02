.syntax unified
	.align 2, 0
	.global ChnVolSetAsm
	.thumb
	.thumb_func
	.type ChnVolSetAsm, %function
ChnVolSetAsm:
	.incbin "roms/B8CJ.gba", 0x11faf0, 0x30
.syntax divided

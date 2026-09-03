.syntax unified
	.text
	.align 2, 0
	.global ChnVolSetAsm
	.thumb
	.thumb_func
	.type ChnVolSetAsm, %function
ChnVolSetAsm:
	.incbin "roms/B8CP.gba", 0x11e594, 0x30
.syntax divided

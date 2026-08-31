.syntax unified
	.align 2, 0
	.global AnimUpdate
	.thumb
	.thumb_func
	.type AnimUpdate, %function
AnimUpdate:
	.incbin "roms/B8CJ.gba", 0x5a64, 0x60
.syntax divided

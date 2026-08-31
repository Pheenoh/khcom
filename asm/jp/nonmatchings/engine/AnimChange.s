.syntax unified
	.align 2, 0
	.global AnimChange
	.thumb
	.thumb_func
	.type AnimChange, %function
AnimChange:
	.incbin "roms/B8CJ.gba", 0x5a00, 0x64
.syntax divided

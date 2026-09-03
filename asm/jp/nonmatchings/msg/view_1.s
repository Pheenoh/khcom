.syntax unified
	.align 2, 0
	.global view_1
	.thumb
	.thumb_func
	.type view_1, %function
view_1:
	.incbin "roms/B8CJ.gba", 0x74550, 0x600
.syntax divided

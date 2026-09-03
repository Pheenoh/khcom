.syntax unified
	.text
	.align 2, 0
	.global view_1
	.thumb
	.thumb_func
	.type view_1, %function
view_1:
	.incbin "roms/B8CP.gba", 0x73a9c, 0x600
.syntax divided

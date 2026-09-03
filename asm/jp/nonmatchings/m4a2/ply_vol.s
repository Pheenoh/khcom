.syntax unified
	.text
	.align 2, 0
	.global ply_vol
	.thumb
	.thumb_func
	.type ply_vol, %function
ply_vol:
	.incbin "roms/B8CJ.gba", 0x11f788, 0x14
.syntax divided

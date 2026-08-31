.syntax unified
	.align 2, 0
	.global ply_endtie
	.thumb
	.thumb_func
	.type ply_endtie, %function
ply_endtie:
	.incbin "roms/B8CJ.gba", 0x11fd20, 0x74
.syntax divided

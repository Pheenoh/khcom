.syntax unified
	.text
	.align 2, 0
	.global ply_note
	.thumb
	.thumb_func
	.type ply_note, %function
ply_note:
	.incbin "roms/B8CJ.gba", 0x11fb20, 0x200
.syntax divided

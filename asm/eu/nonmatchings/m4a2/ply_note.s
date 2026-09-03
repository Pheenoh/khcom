.syntax unified
	.text
	.align 2, 0
	.global ply_note
	.thumb
	.thumb_func
	.type ply_note, %function
ply_note:
	.incbin "roms/B8CP.gba", 0x11e5c4, 0x200
.syntax divided

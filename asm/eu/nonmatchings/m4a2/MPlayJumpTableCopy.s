.syntax unified
	.text
	.align 2, 0
	.global MPlayJumpTableCopy
	.thumb
	.thumb_func
	.type MPlayJumpTableCopy, %function
MPlayJumpTableCopy:
	.incbin "roms/B8CP.gba", 0x11e108, 0x34
.syntax divided

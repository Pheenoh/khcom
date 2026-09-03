.syntax unified
	.text
	.align 2, 0
	.global MPlayMain
	.thumb
	.thumb_func
	.type MPlayMain, %function
MPlayMain:
	.incbin "roms/B8CP.gba", 0x11e2cc, 0x27c
.syntax divided

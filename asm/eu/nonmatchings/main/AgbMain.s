.syntax unified
	.text
	.align 2, 0
	.global AgbMain
	.thumb
	.thumb_func
	.type AgbMain, %function
AgbMain:
	.incbin "roms/B8CP.gba", 0x44c, 0xd4
.syntax divided

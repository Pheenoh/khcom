.syntax unified
	.text
	.align 2, 0
	.global REV_COUNT_0
	.thumb
	.thumb_func
	.type REV_COUNT_0, %function
REV_COUNT_0:
	.incbin "roms/B8CP.gba", 0x98fdc, 0x150
.syntax divided

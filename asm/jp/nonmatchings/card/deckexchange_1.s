.syntax unified
	.text
	.align 2, 0
	.global deckexchange_1
	.thumb
	.thumb_func
	.type deckexchange_1, %function
deckexchange_1:
	.incbin "roms/B8CJ.gba", 0xa789c, 0x13c
.syntax divided

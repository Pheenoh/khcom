.syntax unified
	.text
	.align 2, 0
	.global deckexchange_2
	.thumb
	.thumb_func
	.type deckexchange_2, %function
deckexchange_2:
	.incbin "roms/B8CJ.gba", 0xa8fe8, 0x674
.syntax divided

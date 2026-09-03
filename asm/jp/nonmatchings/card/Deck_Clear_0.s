.syntax unified
	.text
	.align 2, 0
	.global Deck_Clear_0
	.thumb
	.thumb_func
	.type Deck_Clear_0, %function
Deck_Clear_0:
	.incbin "roms/B8CJ.gba", 0xa328c, 0x168
.syntax divided

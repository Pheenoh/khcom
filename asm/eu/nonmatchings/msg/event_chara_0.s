.syntax unified
	.text
	.align 2, 0
	.global event_chara_0
	.thumb
	.thumb_func
	.type event_chara_0, %function
event_chara_0:
	.incbin "roms/B8CP.gba", 0x6cd94, 0x780
.syntax divided

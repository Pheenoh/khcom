.syntax unified
	.text
	.align 2, 0
	.global event_chara_0
	.thumb
	.thumb_func
	.type event_chara_0, %function
event_chara_0:
	.incbin "roms/B8CP.gba", 0x6cdc4, 0x750
.syntax divided

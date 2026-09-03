.syntax unified
	.text
	.align 2, 0
	.global task_hum_lex_rock_1
	.thumb
	.thumb_func
	.type task_hum_lex_rock_1, %function
task_hum_lex_rock_1:
	.incbin "roms/B8CP.gba", 0x5b938, 0x424
.syntax divided

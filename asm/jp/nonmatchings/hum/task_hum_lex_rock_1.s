.syntax unified
	.text
	.align 2, 0
	.global task_hum_lex_rock_1
	.thumb
	.thumb_func
	.type task_hum_lex_rock_1, %function
task_hum_lex_rock_1:
	.incbin "roms/B8CJ.gba", 0x574ac, 0x424
.syntax divided

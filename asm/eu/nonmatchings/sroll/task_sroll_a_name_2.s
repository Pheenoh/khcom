.syntax unified
	.text
	.align 2, 0
	.global task_sroll_a_name_2
	.thumb
	.thumb_func
	.type task_sroll_a_name_2, %function
task_sroll_a_name_2:
	.incbin "roms/B8CP.gba", 0x113148, 0xbc
.syntax divided

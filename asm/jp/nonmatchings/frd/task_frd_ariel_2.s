.syntax unified
	.align 2, 0
	.global task_frd_ariel_2
	.thumb
	.thumb_func
	.type task_frd_ariel_2, %function
task_frd_ariel_2:
	.incbin "roms/B8CJ.gba", 0x47354, 0x110
.syntax divided

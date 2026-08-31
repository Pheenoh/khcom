.syntax unified
	.align 2, 0
	.global task_frd_ariel_1
	.thumb
	.thumb_func
	.type task_frd_ariel_1, %function
task_frd_ariel_1:
	.incbin "roms/B8CJ.gba", 0x46ff8, 0x35c
.syntax divided

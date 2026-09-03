.syntax unified
	.text
	.align 2, 0
	.global task_hum_laxene_1
	.thumb
	.thumb_func
	.type task_hum_laxene_1, %function
task_hum_laxene_1:
	.incbin "roms/B8CP.gba", 0x553ec, 0x13f0
.syntax divided

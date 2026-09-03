.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_circle_1
	.thumb
	.thumb_func
	.type task_bos_dsd_circle_1, %function
task_bos_dsd_circle_1:
	.incbin "roms/B8CJ.gba", 0xc47bc, 0x240
.syntax divided

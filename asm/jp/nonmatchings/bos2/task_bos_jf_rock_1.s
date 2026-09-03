.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_rock_1
	.thumb
	.thumb_func
	.type task_bos_jf_rock_1, %function
task_bos_jf_rock_1:
	.incbin "roms/B8CJ.gba", 0xc0ca8, 0x610
.syntax divided

.syntax unified
	.text
	.align 2, 0
	.global task_bos_md_hahen_1
	.thumb
	.thumb_func
	.type task_bos_md_hahen_1, %function
task_bos_md_hahen_1:
	.incbin "roms/B8CP.gba", 0xfb4c0, 0x5c
.syntax divided

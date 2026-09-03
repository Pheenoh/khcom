.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_lamp_0
	.thumb
	.thumb_func
	.type task_bos_jf_lamp_0, %function
task_bos_jf_lamp_0:
	.incbin "roms/B8CJ.gba", 0xbdc90, 0xc4
.syntax divided

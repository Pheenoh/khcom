.syntax unified
	.align 2, 0
	.global task_bos_jf_lamp_3
	.thumb
	.thumb_func
	.type task_bos_jf_lamp_3, %function
task_bos_jf_lamp_3:
	.incbin "roms/B8CJ.gba", 0xbe300, 0x134
.syntax divided
